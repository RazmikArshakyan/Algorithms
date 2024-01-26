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

    // WGraph g2(6);
    // g2.add_edge(0, 1, 5);
    // g2.add_edge(0, 2, 3);
    // g2.add_edge(1, 3, 6);
    // g2.add_edge(1, 2, 2);
    // g2.add_edge(2, 4, 4);
    // g2.add_edge(2, 5, 2);
    // g2.add_edge(2, 3, 7);
    // g2.add_edge(3, 4, -1);
    // g2.add_edge(4, 5, -2);

    // std::vector<int> sssp = g2.sssp_dag(1);
    // for (int i : sssp)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // WGraph g3(9);
    // g3.add_edge(0, 1, 4);
    // g3.add_edge(1, 2, 11);
    // g3.add_edge(2, 0, 8);
    // g3.add_edge(1, 3, 9);
    // g3.add_edge(3, 2, 7);
    // g3.add_edge(4, 1, 8);
    // g3.add_edge(3, 4, 2);
    // g3.add_edge(3, 5, 6);
    // g3.add_edge(5, 2, 1);
    // g3.add_edge(5, 4, 5);
    // g3.add_edge(4, 6, 4);
    // g3.add_edge(6, 5, 2);
    // g3.add_edge(4, 7, 7);
    // g3.add_edge(7, 6, 14);
    // g3.add_edge(7, 8, 9);
    // g3.add_edge(6, 8, 10);

    // std::vector<int> sssp1 = g3.sssp_dijkstra(0);
    // for (int i : sssp1)
    //     std::cout << i << " ";
    // std::endl(std::cout);

    // WGraph g4(9);
    // g4.add_edge(0, 1, 4);
    // g4.add_edge(1, 2, 11);
    // g4.add_edge(2, 0, 8);
    // g4.add_edge(1, 3, 9);
    // g4.add_edge(3, 2, 7);
    // g4.add_edge(4, 1, 8);
    // g4.add_edge(3, 4, 2);
    // g4.add_edge(3, 5, 6);
    // g4.add_edge(5, 2, 1);
    // g4.add_edge(5, 4, 5);
    // g4.add_edge(4, 6, 4);
    // g4.add_edge(6, 5, 2);
    // g4.add_edge(4, 7, 7);
    // g4.add_edge(7, 6, 14);
    // g4.add_edge(7, 8, 9);
    // g4.add_edge(6, 8, 10);

    // std::vector<int> sssp2 = g4.sssp_bellman_ford(0);
    // for (int i : sssp2)
    //     std::cout << i << " ";
    // std::endl(std::cout);

    // WGraph g5(6);
    // g5.add_edge(0, 1, 5);
    // g5.add_edge(1, 2, 1);
    // g5.add_edge(1, 3, 2);
    // g5.add_edge(3, 4, 2);
    // g5.add_edge(2, 5, 1);
    // g5.add_edge(4, 5, -3);
    // g5.add_edge(5, 3, -1);

    // std::vector<int> sssp3 = g5.sssp_bellman_ford(0);
    // for (int i : sssp3)
    //     std::cout << i << " ";
    // std::endl(std::cout);

    // in this example Dijkstra gave wrong sssp
    // also this example shows why we need to relaxe n - 1 times
    // because after just one iteration we get 2 as a response, but after 2nd iteration which was n - 1th we get the right response
    WGraph g6(3);
    g6.add_edge(0, 1, 2);
    g6.add_edge(0, 2, 3);
    g6.add_edge(2, 1, -2);
    std::vector<int> sssp4 = g6.sssp_bellman_ford(0);
    for (int i : sssp4)
        std::cout << i << " ";
    std::endl(std::cout);
}
