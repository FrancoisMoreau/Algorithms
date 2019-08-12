//
// Created by brayden on 2019-08-11.
//

#include "WeightedQuickUnion.h"

WeightedQuickUnion::WeightedQuickUnion(int N) {
    for (int i = 0; i < N; ++i) {
        id.push_back(i);
    }
    sz = std::move(vector<int>(N, 1));
}

int WeightedQuickUnion::get_root(int n) {
    if (id[n] == n)
        return n;
    else {
        id[n] = id[id[n]];
        return get_root(id[n]);
    }
}

bool WeightedQuickUnion::connected(int p, int q) {
    if (get_root(p) == get_root(q))
        return true;
    else
        return false;
}

void WeightedQuickUnion::unite(int p, int q) {
    //every root keeps the size
    int rootp = get_root(p);
    int rootq = get_root(q);
    if (rootp == rootq) return;
    if (sz[rootp] < sz[rootq]) {
        id[rootp] = rootq;
        sz[rootq] += sz[rootp];
    } else {
        id[rootq] = rootp;
        sz[rootp] += sz[rootq];
    }
}

