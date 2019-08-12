//
// Created by brayden on 2019-08-10.
//

#include "QuickFind.h"

QuickFind::QuickFind(int N) {
    for (int i = 0; i < N; ++i) {
        id.push_back(i);
    }
}

bool QuickFind::connected(int p, int q) {
    if (id[p] == id[q])
        return true;
    else
        return false;
}

void QuickFind::unite(int p, int q) {
    int pid = id[p];
    int qid = id[q];
    for (auto &i : id) {
        if (i == pid)
            i = qid;
    }
}

