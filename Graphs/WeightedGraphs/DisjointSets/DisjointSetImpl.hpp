#include "DisjointSet.hpp"

inline DisjointSet::DisjointSet(int size)
    : rank(size, 0), parent(size) 
{
    for (int i = 0; i < size; ++i) 
        parent[i] = i;
}

inline void DisjointSet::unify(int A, int B)
{
    int rootA = find_root(A);
    int rootB = find_root(B);

    if (rootA == rootB)
        return;

    if (rank[rootA] < rank[rootB]) {
        parent[rootA] = parent[rootB];
    }
    else if (rank[rootA] > rank[rootB]) {
        parent[rootB] = parent[rootA];
    }
    else {
        parent[rootB] = parent[rootA];
        ++rank[rootA];
    }
}

int DisjointSet::find_root(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = find_root(parent[a]);
}