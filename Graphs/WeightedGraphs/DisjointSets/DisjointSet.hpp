#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <vector>

class DisjointSet {
public: 
    DisjointSet(int size);
    ~DisjointSet() = default;
    void unify(int A, int B);
    int find_root(int a);

private: 
    std::vector<int> rank;
    std::vector<int> parent;
};

#include "DisjointSetImpl.hpp"
#endif