#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <forward_list>
#include <vector>
#include <queue>
#include <stack>
#include <array>

class Graph {
public:  
    Graph(int vertices);
    ~Graph();
    void add_edge(int u, int w);
    void print_adj_list() const;
    void print_adj_matrix() const;
    void bfs(int v);
    void dfs(int v);
    void dfs_it(int v);
    Graph transpose();
    std::vector<int> shortest_path(int src, int dest);
    int count_nodes(int src, int level);
    std::vector<std::vector<int>> all_paths(int src, int dest);
    int count_of_connected_components();
    bool is_cyclic_undirected();
    bool is_cyclic_directed();
    std::vector<int> topological_sort();
    std::vector<int> kahns_algorithm();
    std::vector<std::vector<int>> brute_force_scc();
    std::vector<std::vector<int>> kosaraju_scc();
    std::vector<int> articulation_points();

private:
    int vertices;
    std::forward_list<int>* adjacency_list;
    bool** adjacency_matrix;

    void dfs_ap(std::vector<bool>& visited, int removed, int curr);
    int kahns_has_cycle(const std::vector<int>& indegree);
    bool is_cyclic_undirected(int v, std::vector<bool>& visited, int parent = 0);
    bool is_cyclic_directed(int v, std::vector<bool>& visited, std::vector<bool>& rec_stack);
    void no_print_dfs(int v, std::vector<bool>& visited);
    void dfs(int v, std::vector<bool>& visited);
    void all_paths(int src, int dest, std::vector<bool>& visited,
        std::vector<int>& path, std::vector<std::vector<int>>& paths);
    void topological_sort(int v, std::vector<bool>& visited, std::stack<int>& on_stack);
    bool dfs_scc(int src, int dest, std::vector<bool>& visited);
    bool is_path(int src, int dest);
    void dfs_kosaraju(int v, std::vector<bool>& visited, std::vector<int>& scc);
    void dfs_kosaraju(int v, std::vector<bool>& visited, std::stack<int>& stk);
};

#include "GraphImpl.hpp"
#endif
