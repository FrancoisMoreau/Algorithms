//
// Created by brayden on 2019-08-17.
//

#include "UFCanonical.h"

UFCanonical::UFCanonical(int n) : sz(std::move(vector<int>(n, 1))) {
    for (int i = 0; i < n; ++i) {
        id.push_back(i);
    }
}

int UFCanonical::root(int p) {
    while (p != id[p]) {
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

bool UFCanonical::connected(int p, int q) {
    if (root(p) == root(q))
        return true;
    else
        return false;
}

void UFCanonical::balance_root(int start, int start_root, int final_root) {
    if (sz[start_root] > sz[final_root]) {
        while (start != start_root) {
            int tmp = id[start];
            start = id[id[start]];
            id[tmp] = final_root;
        }
    }
    id[start_root] = final_root;
    sz[final_root] = sz[start_root];
}

void UFCanonical::unite(int p, int q) {
    if (connected(p, q))
        return;
    int p_root = root(p);
    int q_root = root(q);
    if (p_root < q_root) {
        balance_root(p, p_root, q_root);
    } else {
        balance_root(q, q_root, p_root);
    }
}

int UFCanonical::find(int k) {
    return root(k);
}
