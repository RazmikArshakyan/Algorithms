#include "WGraph.hpp"

WGraph::WGraph(int vertices)
    : vertices(vertices), adjacency_list(vertices)
{
}

inline void WGraph::add_edge(int u, int v, int w)
{
    adjacency_list[u].push_back({v, w});
    // adjacency_list[v].push_back({u, w}); // for undirected graphs
}

inline int WGraph::mst_prim(int src)
{
    int total = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>> pq;
    std::vector<bool> visited(vertices, false);

    pq.push({0, src});
    while (!pq.empty()) {
        auto[weight, vertex] = pq.top();

        pq.pop();
        
        if (visited[vertex])
            continue;
        visited[vertex] = true;

        total += weight;
        for (auto v : adjacency_list[vertex]) 
            if (!visited[v.first])
               pq.push({v.second, v.first});
    }
    return total;
}

inline int WGraph::mst_kruskal()
{
    int total = 0;
    auto edges = adjacency_list_to_edges();

    DisjointSet ds(vertices);
    for (auto edge : edges) {
        if (ds.find_root(edge[0]) != ds.find_root(edge[1])) {
            total += edge[2];
            ds.unify(edge[0], edge[1]);
        }
    }
    return total;
}

inline std::vector<int> WGraph::top_sort()
{
    std::vector<int> indegree(vertices, 0);
    std::queue<int> q;
    std::vector<int> topological_order;

    for (int i = 0; i < vertices; ++i)
        for (auto vertex : adjacency_list[i])
            ++indegree[vertex.first];
    
    for (int i = 0; i < vertices; ++i)
        if (indegree[i] == 0)
            q.push(i);
    
    while (!q.empty()) {
        auto vertex = q.front();
        q.pop();

        topological_order.push_back(vertex);

        for (auto v : adjacency_list[vertex])
            if (--indegree[v.first] == 0)
                q.push(v.first);
    }

    if (topological_order.size() == vertices)
        return topological_order;
    return {};
}

inline std::vector<int> WGraph::sssp_dag(int src)
{
    std::vector<int> dist(vertices, INT_MAX);
    
    auto sorted = top_sort();
    dist[src] = 0;

    for (auto elem : sorted)
        if (dist[elem] != INT_MAX)
            for (auto vertex : adjacency_list[elem])
                if (dist[vertex.first] > dist[elem] + vertex.second)
                    dist[vertex.first] = dist[elem] + vertex.second;
    return dist;
}

inline std::vector<int> WGraph::sssp_dijkstra(int src)
{
    std::vector<int> dist(vertices, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>> pq;
    std::vector<bool> visited(vertices, false);

    dist[src] = 0;
    pq.push({src, 0});

    while (!pq.empty()) {
        auto[vertex, weight] = pq.top();
        pq.pop();

        if (dist[vertex] < weight)
            continue;
        visited[vertex] = true;

        for (auto v : adjacency_list[vertex]) {
            if (!visited[v.first]) {
                if (dist[v.first] > dist[vertex] + v.second) {
                    dist[v.first] = dist[vertex] + v.second;
                    pq.push({v.first, dist[v.first]});
                }
            }
        }        
    }
    return dist;
}

inline std::vector<int> WGraph::sssp_bellman_ford(int src)
{
    std::vector<int> dist(vertices, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            for (auto vertex : adjacency_list[j]) {
                if (dist[vertex.first] > dist[j] + vertex.second) {
                    dist[vertex.first] = dist[j] + vertex.second;
                }
            }
        }
    }

    for (int i = 0; i < vertices; ++i) {
        for (auto vertex : adjacency_list[i]) {
            if (dist[vertex.first] > dist[i] + vertex.second) {
                std::cout << "Ill formed graph\n";
                return {};
            }
        }
    }
    return dist;
}

inline std::vector<std::vector<int>> WGraph::adjacency_list_to_edges()
{
    std::vector<std::vector<int>> edges; 

    for (int i = 0; i < vertices; ++i) {
        for (auto vertex : adjacency_list[i]) {
            std::vector<int> edge;
            edge.push_back(i); 
            edge.push_back(vertex.first);
            edge.push_back(vertex.second);
            edges.push_back(edge);
        }
    }

    std::sort(edges.begin(), edges.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[2] < b[2];
    });

    return edges;
}
