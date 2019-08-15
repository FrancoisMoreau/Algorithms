//
// Created by brayden on 2019-08-10.
//

#include "QuickUnion.h"

QuickUnion::QuickUnion(int N) {
    for (int i = 0; i < N; ++i) {
        id.push_back(i);
    }
}

int QuickUnion::get_root(int n) {
    if (id[n] == n)
        return n;
    else
        return get_root(id[n]);
}

bool QuickUnion::connected(int p, int q) {
    if (get_root(p) == get_root(q))
        return true;
    else
        return false;
}

void QuickUnion::unite(int p, int q) {
    id[get_root(p)] = q;
}

