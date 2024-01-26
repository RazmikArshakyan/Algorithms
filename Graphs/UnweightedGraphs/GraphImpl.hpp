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
    // adjacency_matrix[w][u] = true; // for undirected graphs
}

inline void Graph::print_adj_list() const
{
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Vertex " << i << " - ";
        for (int edge : adjacency_list[i])
            std::cout << edge << " ";
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
        for (int j = 0; j < vertices; ++j) 
            std::cout << adjacency_matrix[i][j] << " ";
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
    std::vector<bool> visited(vertices, false);
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
    visited[v] = true;

    for (auto vertex : adjacency_list[v]) 
        if (!visited[vertex])
            no_print_dfs(vertex, visited);
}

inline void Graph::dfs(int v, std::vector<bool> &visited)
{
    visited[v] = true;
    std::cout << v << " ";

    for (auto vertex : adjacency_list[v])
        if (!visited[vertex]) 
            dfs(vertex, visited);
}

inline Graph Graph::transpose()
{
    Graph g(vertices);
    for (int i = 0; i < vertices; ++i) 
        for (int edge : adjacency_list[i]) 
            g.add_edge(edge, i);

    return g;
}

inline std::vector<int> Graph::shortest_path(int src, int dest)
{
    if (src == dest) 
        return {};

    std::vector<bool> visited(vertices, false);
    std::vector<int> parent(vertices, -1);

    std::queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        if (v == dest)
            break; 
            
        for (auto vertex : adjacency_list[v]) {
            if (!visited[vertex]) {
                q.push(vertex);
                parent[vertex] = v;
                visited[vertex] = true; 
            }
        }
    }

    std::vector<int> shortest_path;
    int curr = dest;
    while (curr != -1) {
        shortest_path.insert(shortest_path.begin(), curr);
        curr = parent[curr];
    }

    return shortest_path;
}

inline int Graph::count_nodes(int src, int level)
{
    std::vector<bool> visited(vertices, false);
    std::queue<std::pair<int, int>> q;

    q.push({src, 0});
    visited[src] = true;

    int count = 0;
    while (!q.empty()) {
        auto[curr_vertex, curr_level] = q.front();
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
    std::vector<bool> visited(vertices, false);
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

inline bool Graph::is_cyclic_directed(int v, std::vector<bool> &visited, std::vector<bool>& rec_stack)
{
    visited[v] = true;
    rec_stack[v] = true;

    for (auto vertex : adjacency_list[v]) {
        if (!visited[vertex] && is_cyclic_directed(vertex, visited, rec_stack))
            return true;
        else if (rec_stack[vertex])
            return true;
    }
    
    rec_stack[v] = false;
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
    std::vector<bool> rec_stack(vertices, false);

    return is_cyclic_directed(0, visited, rec_stack);
}

inline std::vector<int> Graph::topological_sort()
{
    if (is_cyclic_directed()) {
        std::cout << "Can't be sorted topologically\n";
        return {};
    }

    std::vector<bool> visited(vertices, false);
    std::stack<int> stk;

    for (int i = 0; i < vertices; ++i)
        if (!visited[i])
            topological_sort(i, visited, stk);

    std::vector<int> topological_order;
    while (!stk.empty()) {
        int val  = stk.top();
        stk.pop();
        topological_order.push_back(val);
    }

    return topological_order;
}

inline void Graph::topological_sort(int v, std::vector<bool>& visited, std::stack<int>& on_stack)
{
    visited[v] = true;

    for (auto vertex : adjacency_list[v])
        if (!visited[vertex])
            topological_sort(vertex,visited, on_stack);
    
    on_stack.push(v);
}

inline void Graph::dfs_ap(std::vector<bool>& visited, int removed, int curr)
{
    visited[curr] = true;

    for (auto vertex : adjacency_list[curr]) 
        if (vertex != removed) 
            if (!visited[vertex])
                dfs_ap(visited, removed, vertex);
}

inline int Graph::kahns_has_cycle(const std::vector<int> &indegree)
{
    int ctr = 0;
    for (auto num : indegree)
        if (num == 0)
            ctr++;
    
    return ctr;
}

inline std::vector<int> Graph::kahns_algorithm()
{
    std::vector<int> indegree(vertices);

    for (int i = 0; i < vertices; ++i) 
        for (auto vertex : adjacency_list[i]) 
            ++indegree[vertex];

    if (kahns_has_cycle(indegree) == 0) {
        std::cout << "Graph has cycle, so can't be sorted in topological order\n";
        return {};
    }

    std::queue<int> q;
    for (int i = 0; i < vertices; ++i) 
        if (indegree[i] == 0)
            q.push(i);

    std::vector<int> topological_order;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        topological_order.push_back(v);

        for (auto vertex : adjacency_list[v])
            if (--indegree[vertex] == 0)
                q.push(vertex);
    }    
    
    return topological_order;
}

inline std::vector<std::vector<int>> Graph::brute_force_scc()
{
    std::vector<bool> is_scc(vertices, false);

    std::vector<std::vector<int>> sccs;
    for (int i = 0; i < vertices; ++i) {
        if (!is_scc[i]) {
            std::vector<int> scc;
            is_scc[i] = true;
            scc.push_back(i);

            for (int j = i + 1; j < vertices; ++j) {
                if (is_path(i, j) && is_path(j, i)) {
                    is_scc[j] = true;
                    scc.push_back(j);
                }
            }

            sccs.push_back(scc);
        }
    }
    return sccs;
}

inline std::vector<std::vector<int>> Graph::kosaraju_scc()
{
    std::vector<bool> visited(vertices, false);
    std::stack<int> stk;
   
    for (int i = 0; i < vertices; ++i)
        if (!visited[i])
            dfs_kosaraju(i, visited, stk);
    
    Graph graph_transpose = this->transpose();

    std::fill(visited.begin(), visited.end(), false);

    std::vector<std::vector<int>> sccs;
    while (!stk.empty()) {
        auto vertex = stk.top();
        stk.pop();

        if (!visited[vertex]) {
            std::vector<int> scc;
            graph_transpose.dfs_kosaraju(vertex, visited, scc);

            sccs.push_back(scc);
        }
    } 

    return sccs;
}

inline std::vector<int> Graph::articulation_points()
{
    std::vector<int> aps;
    for (int i = 0; i < vertices; ++i) {
        int component = 0;
        std::vector<bool> visited(vertices, false);
        for (int j = 0; j < vertices; ++j) {
            if (i != j) {
                if (!visited[j]) {
                    component++;
                    dfs_ap(visited, i, j);
                }
            }
        }

        if (component > 1)
            aps.push_back(i);
    }

    return aps;
}

inline std::vector<std::vector<int>> Graph::tarjan_scc()
{
    std::vector<int> ids(vertices, -1);
    std::vector<int> low_links(vertices, 0);
    std::vector<bool> rec_stack(vertices, false);
    std::stack<int> stk;
    std::vector<std::vector<int>> sccs;

    for (int i = 0; i < vertices; ++i) 
        if (ids[i] == -1)
            dfs_tarjan(i, ids, low_links, rec_stack, stk, sccs);
    return sccs;
}

inline void Graph::dfs_kosaraju(int v, std::vector<bool>& visited, std::vector<int>& scc)
{
    visited[v] = true;

    for (auto vertex : adjacency_list[v]) 
        if (!visited[vertex])
            dfs_kosaraju(vertex, visited, scc);

    scc.push_back(v);
}

inline void Graph::dfs_kosaraju(int v, std::vector<bool>& visited, std::stack<int>& stk)
{
    visited[v] = true;

    for (auto vertex : adjacency_list[v]) 
        if (!visited[vertex])
            dfs_kosaraju(vertex, visited, stk);

    stk.push(v);    
}

inline void Graph::dfs_tarjan(int src, std::vector<int> &ids, std::vector<int> &low_links, std::vector<bool> &rec_stack, std::stack<int> &stk, std::vector<std::vector<int>>& sccs)
{
    static int id = 0;
    rec_stack[src] = true;

    low_links[src] = ids[src] = id++;
    stk.push(src);
    for (auto vertex : adjacency_list[src]) {
        if (ids[vertex] == -1)
            dfs_tarjan(vertex, ids, low_links, rec_stack, stk, sccs);
        if (rec_stack[vertex])
            low_links[src] = std::min(low_links[src], low_links[vertex]);
    }
    if (low_links[src] == ids[src]) {
        std::vector<int> scc;
        for (auto i = stk.top(); ; i = stk.top()) {
            scc.push_back(i);
            stk.pop();
            rec_stack[i] = false;

            if (i == src)
                break;
        }
        sccs.push_back(scc);
    }
}

inline bool Graph::dfs_scc(int src, int dest, std::vector<bool> &visited)
{
    if (src == dest)
        return true;

    visited[src] = true;
    for (auto vertex : adjacency_list[src])
        if (!visited[vertex])
            if (dfs_scc(vertex, dest, visited))
                return true;
    return false;
}

inline bool Graph::is_path(int src, int dest)
{
    std::vector<bool> visited(vertices, false);
    return dfs_scc(src, dest, visited);
}
