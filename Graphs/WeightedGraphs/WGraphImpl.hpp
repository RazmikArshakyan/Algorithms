#include "WGraph.hpp"

WGraph::WGraph(int vertices)
    : vertices(vertices), adjacency_list(vertices)
{
}

inline void WGraph::add_edge(int u, int v, int w)
{
    adjacency_list[u].push_back({v, w});
    adjacency_list[v].push_back({u, w}); // for undirected graphs
}

inline int WGraph::mst_prim(int src)
{
    int total = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>> pq;
    std::vector<bool> visited(vertices, false);

    pq.push({0, src});
    while (!pq.empty()) {
        auto vertex = pq.top().second;
        auto weight = pq.top().first;
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
