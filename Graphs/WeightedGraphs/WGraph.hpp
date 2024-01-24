#ifndef WGRAPH_H
#define WGRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include "DisjointSets/DisjointSet.hpp"

class WGraph {
public:  
    WGraph(int vertices);
    ~WGraph() = default;
    void add_edge(int u, int v, int w);
    int mst_prim(int src);
    int mst_kruskal();
    std::vector<int> top_sort();
    std::vector<int> sssp_dag(int src);
    std::vector<int> sssp_dijkstra(int src);
    std::vector<int> sssp_bellman_ford(int src);

private: 
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjacency_list;

    std::vector<std::vector<int>> adjacency_list_to_edges();
};

#include "WGraphImpl.hpp"
#endif
