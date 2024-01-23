#ifndef WGRAPH_H
#define WGRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "DisjointSets/DisjointSet.hpp"

class WGraph {
public:  
    WGraph(int vertices);
    ~WGraph() = default;
    void add_edge(int u, int v, int w);
    int mst_prim(int src);
    int mst_kruskal();

private: 
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjacency_list;

    std::vector<std::vector<int>> adjacency_list_to_edges();
};

#include "WGraphImpl.hpp"
#endif