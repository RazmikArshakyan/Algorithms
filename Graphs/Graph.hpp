#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <forward_list>
#include <vector>
#include <queue>
#include <stack>

class Graph {
public:  
    Graph(int vertices);
    void add_edge(int u, int w);
    void print_adj_list() const;
    void bfs(int v);
    void dfs(int v);
    void dfs_it(int v);
    void transpose();
    std::vector<int> shortest_path(int src, int dest);
    int count_nodes(int src, int level);
    std::vector<std::vector<int>> all_paths(int src, int dest);
    int count_of_connected_components();

private:
    int vertices;
    std::forward_list<int>* adjacency_list;

    void no_print_dfs(int v, std::vector<bool>& visited);
    void dfs(int v, std::vector<bool>& visited);
    void all_paths(int src, int dest, std::vector<bool>& visited,
        std::vector<int>& path, std::vector<std::vector<int>>& paths);
};

#include "GraphImpl.hpp"
#endif