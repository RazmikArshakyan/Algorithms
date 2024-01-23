#include <iostream>

#include "WGraph.hpp"

int main() {
    WGraph g1(9);
    g1.add_edge(0, 1, 4);
    g1.add_edge(0, 2, 8);
    g1.add_edge(1, 2, 11);
    g1.add_edge(1, 3, 8);
    g1.add_edge(3, 4, 2);
    g1.add_edge(2, 4, 7);
    g1.add_edge(4, 5, 6);
    g1.add_edge(2, 5, 1);
    g1.add_edge(5, 6, 2);
    g1.add_edge(3, 6, 4);
    g1.add_edge(3, 7, 7);
    g1.add_edge(6, 7, 14);
    g1.add_edge(7, 8, 9);
    g1.add_edge(6, 8, 10);
    
    std::cout << g1.mst_prim(5) << std::endl;
    std::cout << g1.mst_kruskal() << std::endl;
}