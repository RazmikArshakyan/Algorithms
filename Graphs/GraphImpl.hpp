#include "Graph.hpp"

Graph::Graph(int vertices)
    : vertices{vertices}
{
    adjacency_list = new std::forward_list<int>[vertices];

    adjacency_matrix = new bool*[vertices]();
    for (int i = 0; i < vertices; ++i) {
        adjacency_matrix[i] = new bool[vertices]();
    }
}

inline Graph::~Graph()
{
    delete[] adjacency_list;

    for (int i = 0; i < vertices; ++i)
        delete adjacency_matrix[i];
    
    delete[] adjacency_matrix;
}

inline void Graph::add_edge(int u, int w)
{
    // for adjacency_list
    adjacency_list[u].push_front(w);
    // adjacency_list[w].push_front(u); // for undirected graphs

    // for adjacency_matrix
    adjacency_matrix[u][w] = true;
    adjacency_matrix[w][u] = true; // for undirected graphs
}

inline void Graph::print_adj_list() const
{
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Vertex " << i << " - ";
        for (int edge : adjacency_list[i]) {
            std::cout << edge << " ";
        }
        std::cout << std::endl;
    }
}

inline void Graph::print_adj_matrix() const
{
    std::cout << "V/E ";
    for (int i = 0; i < vertices; ++i)
        std::cout << i << " ";
    
    std::cout << std::endl;
        
    for (int i = 0; i < vertices; ++i) {
        std::cout << i << " : ";
        for (int j = 0; j < vertices; ++j) {
            std::cout << adjacency_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

inline void Graph::bfs(int v)
{
    std::vector<bool> visited(vertices, false);
    visited[v] = true;

    std::queue<int> q;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        std::cout << v << " ";
        q.pop();

        for (auto vertex : adjacency_list[v]) {
            if (!visited[vertex]) {
                visited[vertex] = true;
                q.push(vertex);
            }
        }
    }
}

inline void Graph::dfs(int v)
{
    std::vector<bool> visited;
    dfs(v, visited);
}

inline void Graph::dfs_it(int v)
{
    std::vector<bool> visited(vertices, false);
    visited[v] = true;

    std::stack<int> stk;
    stk.push(v);

    while (!stk.empty()) {
        v = stk.top();
        std::cout << v << " ";
        stk.pop();

        for (auto vertex : adjacency_list[v]) {
            if (!visited[vertex]) {
                visited[vertex] = true;
                stk.push(vertex);
            }
        }
    }
}

inline void Graph::no_print_dfs(int v, std::vector<bool> &visited)
{
    if (visited.empty())
        visited = std::vector<bool>(v, false);
    
    visited[v] = true;
    for (auto vertex : adjacency_list[v]) 
        if (!visited[vertex])
            no_print_dfs(vertex, visited);
}

inline void Graph::dfs(int v, std::vector<bool> &visited)
{
    if (visited.empty())
        visited = std::vector<bool>(v, false);
    
    visited[v] = true;
    std::cout << v << " ";
    for (auto vertex : adjacency_list[v])
        if (!visited[vertex]) 
            dfs(vertex, visited);
}

inline void Graph::transpose()
{
    std::forward_list<int>* new_adjacency_list = new std::forward_list<int>[vertices];
    for (int i = 0; i < vertices; ++i) {
        for (int edge : adjacency_list[i]) {
            new_adjacency_list[edge].push_front(i);
        }
    }
    delete[] adjacency_list;

    adjacency_list = new_adjacency_list;
}

inline std::vector<int> Graph::shortest_path(int src, int dest)
{
    std::vector<std::vector<int>> paths = all_paths(src, dest);
    std::vector<int> path = paths[0];
    for (auto p : paths) 
        if (p.size() < path.size())
            path = p;
            
    return path;
}

inline int Graph::count_nodes(int src, int level)
{
    std::vector<bool> visited(vertices, false);
    std::queue<std::pair<int, int>> q;

    q.push({src, 0});
    visited[src] = true;

    int count = 0;
    while (!q.empty()) {
        int curr_vertex = q.front().first;
        int curr_level = q.front().second;
        q.pop();

        if (curr_level == level)
            count++;

        for (auto neighbour : adjacency_list[curr_vertex]) {
            if (!visited[neighbour]) {
                q.push({neighbour, curr_level + 1});
                visited[neighbour] = true;
            }
        }
    }

    return count;
}

inline void Graph::all_paths(int src, int dest, std::vector<bool>& visited,
    std::vector<int>& path, std::vector<std::vector<int>>& paths)
{
    if (visited.empty())
        visited = std::vector<bool>(vertices, false);

    if (visited[src])
       return;
    
    if (src == dest) {
        path.push_back(src);
        paths.push_back(path);
        path.pop_back();
        return;
    }

    visited[src] = true;
    path.push_back(src);
    for (auto vertex : adjacency_list[src])
        if (!visited[vertex])
            all_paths(vertex, dest, visited, path, paths);

    visited[src] = false;
    path.pop_back();
}

inline std::vector<std::vector<int>> Graph::all_paths(int src, int dest)
{
    std::vector<std::vector<int>> paths;
    std::vector<int> path;
    std::vector<bool> visited;
    all_paths(src, dest, visited, path, paths);
    
    return paths;
}

inline int Graph::count_of_connected_components()
{
    std::vector<bool> visited(vertices, false);

    int count = 0;
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            no_print_dfs(i, visited);
            count++;
        }
    }

    return count;
}

inline bool Graph::is_cyclic_undirected(int v, std::vector<bool> &visited, int parent)
{
    visited[v] = true;

    for (auto vertex : adjacency_list[v]) {
        if (!visited[vertex]) {
            if (is_cyclic_undirected(vertex, visited, v))
                return true;
        }
        else {
            if (vertex != parent) 
                return true;
        }
    }

    return false;
}

inline bool Graph::is_cyclic_directed(int v, std::vector<bool> &visited, int parent)
{
    visited[v] = true;
    //visited[parent] = false;

    for (auto vertex : adjacency_list[v]) {
        if (!visited[vertex]) {
            if (is_cyclic_directed(vertex, visited, v))
                return true;
        }
        else  {
            if (parent != vertex)
                return true;
        }
    }

    return false;
}

inline bool Graph::is_cyclic_undirected()
{
    std::vector<bool> visited(vertices, false);
    return is_cyclic_undirected(0, visited);
}

inline bool Graph::is_cyclic_directed()
{
    std::vector<bool> visited(vertices, false);
    return is_cyclic_directed(0, visited);
}