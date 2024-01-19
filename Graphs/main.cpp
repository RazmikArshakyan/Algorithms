#include <iostream>
#include <vector>

#include "Graph.hpp"

int main() {
    // Graph g1(6);
    // g1.add_edge(0, 1);
    // g1.add_edge(0, 3);
    // g1.add_edge(1, 2);
    // g1.add_edge(2, 5);
    // g1.add_edge(2, 3);
    // g1.add_edge(3, 5);
    // g1.add_edge(3, 4);
    // g1.add_edge(4, 5);

    // g1.print_adj_list();
    // std::cout << "BFS ";
    // g1.bfs(0);
    // std::cout << std::endl;
    // std::cout << "DFS iterative ";
    // g1.dfs_it(3);
    // std::cout << std::endl;
    // std::cout << "DFS recursive ";
    // std::vector<bool> visited;
    // g1.dfs(3);

    // std::cout << std::endl;
    // g1.transpose();
    // std::cout << "Adjacency list after transpose \n";
    // g1.print_adj_list();

    // std::cout << std::endl;
    // std::cout << "All possible paths from source to dest \n";
    // std::vector<std::vector<int>> paths = g1.all_paths(0, 5);
    // for (auto path : paths) {
    //     for (auto i : path)
    //         std::cout << i << " "; 
    //     std::cout << std::endl;
    // }

    // std::cout << "Shortest path in the graph from given src and dest" << std::endl;
    // std::vector<int> shortest_path = g1.shortest_path(0, 5);
    // for (auto val : shortest_path)
    //     std::cout << val << " ";
    // std::cout << std::endl;
    
    // Graph g2(6);

    // g2.add_edge(0, 1);
    // g2.add_edge(0, 2);
    // g2.add_edge(1, 3);
    // g2.add_edge(3, 2);
    // g2.add_edge(4, 2);
    // g2.add_edge(2, 5);

    // std::cout << "Counting nodes at src ";
    // std::cout << g2.count_nodes(0, 2);
    // std::cout << std::endl;

    // std::cout << "Count of connected components ";
    // Graph g3(5);
    // g3.add_edge(0, 1);
    // g3.add_edge(0, 2);
    // g3.add_edge(1, 2);

    // std::cout << g3.count_of_connected_components(); 
    
    // std::cout << "\nAnother test of connected components\nCount of connected componenets ";
    // Graph g4(6);
    // g4.add_edge(0, 1);
    // g4.add_edge(0, 3);
    // g4.add_edge(4, 2);

    // std::cout << g4.count_of_connected_components();
    // std::cout << std::endl;

    // std::cout << "Printing adjacency matrix of graph\n";
    // Graph g5(4);
    // g5.add_edge(0, 1);
    // g5.add_edge(1, 2);
    // g5.add_edge(1, 3);
    // g5.add_edge(2, 3);

    // g5.print_adj_matrix();

    // std::cout << "Checking if we have cycle in undirected graph ";
    // Graph g6(4);
    // g6.add_edge(0, 1);
    // g6.add_edge(0, 2);
    // g6.add_edge(1, 3);
    // g6.add_edge(2, 3);
    
    // std::cout << g6.is_cyclic_undirected();

    // std::cout << "\nAnother check\n";
    // std::cout << "Checking if we have cycle in undirected graph ";
    // Graph g7(5);
    // g7.add_edge(0, 1);
    // g7.add_edge(1, 4);
    // g7.add_edge(1, 3);
    // g7.add_edge(2, 3);
    // g7.add_edge(2, 4);
    
    // std::cout << g7.is_cyclic_undirected();

    // std::cout << "\nAnother check\n";
    // std::cout << "Checking if we have cycle in undirected graph ";
    // Graph g8(4);
    // g8.add_edge(0, 1);
    // g8.add_edge(0, 3);
    // g8.add_edge(1, 2);
    
    // std::cout << g8.is_cyclic_undirected();
    
    // std::cout << "\nChecking if we have cycle in directed graph ";
    // Graph g9(4);
    // g9.add_edge(0, 2);
    // g9.add_edge(2, 3);
    // g9.add_edge(3, 1);
    // g9.add_edge(1, 0);

    // std::cout << g9.is_cyclic_directed();

    // std::cout << "\nAnother check\n";
    // std::cout << "Checking if we have cycle in directed graph ";
    // Graph g10(5);
    // g10.add_edge(0, 1);
    // g10.add_edge(1, 2);
    // g10.add_edge(1, 3);
    // g10.add_edge(2, 4);
    // g10.add_edge(3, 4);

    // std::cout << g10.is_cyclic_directed();

    // std::cout << "\nSorting graph in topological order\n";
    // Graph g11(5);
    // g11.add_edge(0, 1);
    // g11.add_edge(1, 2);
    // g11.add_edge(2, 3);
    // g11.add_edge(3, 4);
    // g11.add_edge(4, 1);

    // std::vector<int> ts1 = g11.topological_sort();
    // for (auto it : ts1)
    //     std::cout << it;

    // std::cout << "Another example\n";
    // std::cout << "Sorting graph in topological order\n";
    // Graph g12(6);
    // g12.add_edge(0, 1);
    // g12.add_edge(0, 2);
    // g12.add_edge(2, 3);
    // g12.add_edge(3, 1);
    // g12.add_edge(1, 4);
    // g12.add_edge(3, 4);
    // g12.add_edge(4, 5);

    // std::vector<int> ts2 = g12.topological_sort();
    // for (auto elem : ts2)
    //     std::cout << elem  << " ";

    // std::cout << "\nSorting graph in topological order with Kahn's algorithm\n";
    // Graph g13(4);
    // g13.add_edge(0, 1);
    // g13.add_edge(1, 2);
    // g13.add_edge(2, 3);
    // g13.add_edge(3, 0);

    // std::vector<int> ts3 = g13.kahns_algorithm();

    // std::cout << "Another check\n";
    // std::cout << "Sorting graph in topological order with Kahn's algorithm\n";
    // Graph g14(6);
    // g14.add_edge(5, 0);
    // g14.add_edge(4, 0);
    // g14.add_edge(5, 2);
    // g14.add_edge(2, 3);
    // g14.add_edge(3, 1);
    // g14.add_edge(4, 1);

    // std::vector<int> ts4 = g14.kahns_algorithm();
    // for (auto num : ts4) 
    //     std::cout << num << " ";

    // std::cout << "\nFinding SCCs of graph\n";
    // Graph g15(5);
    // g15.add_edge(0, 2);
    // g15.add_edge(2, 1);
    // g15.add_edge(1, 0);
    // g15.add_edge(0, 3);
    // g15.add_edge(3, 4);

    // // Not recommended as time complexity is O(N^3)
    // std::vector<std::vector<int>> sccs1 = g15.brute_force_scc();
    // for (auto scc : sccs1) {
    //     for (auto vertex : scc)
    //         std::cout << vertex << " ";
    //     std::cout << std::endl;
    // }

    // std::cout << "Finding SCCs, using Kosarajus algorithm\n";
    // Graph g16(7);
    // g16.add_edge(0, 2);
    // g16.add_edge(2, 3);
    // g16.add_edge(3, 1);
    // g16.add_edge(1, 0);
    // g16.add_edge(1, 4);
    // g16.add_edge(4, 5);
    // g16.add_edge(5, 4);
    // g16.add_edge(5, 6);
    // g16.add_edge(3, 5);

    // std::vector<std::vector<int>> sccs2 = g16.kosaraju_scc();
    // for (auto scc : sccs2) {
    //     for (auto vertex : scc)
    //         std::cout << vertex << " ";
    //     std::cout << std::endl;
    // }   
    
    // std::cout << "Another test\n";
    // Graph g17(6);
    // g17.add_edge(0, 1);
    // g17.add_edge(1, 2);
    // g17.add_edge(2, 0);
    // g17.add_edge(3, 4);
    // g17.add_edge(4, 3);

    // std::vector<std::vector<int>> sccs3 = g17.kosaraju_scc();
    // for (auto scc : sccs3) {
    //     for (auto vertex : scc)
    //         std::cout << vertex << " ";
    //     std::cout << std::endl;
    // }

    Graph g18(6);
    g18.add_edge(0, 1);
    g18.add_edge(0, 2);
    g18.add_edge(2, 4);
    g18.add_edge(3, 1);
    g18.add_edge(4, 5);

    std::vector<int> aps1 = g18.articulation_points();
    for (auto ap : aps1) 
        std::cout << ap << " ";

    return 0;
}
