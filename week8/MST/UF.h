//
// Created by brayden on 2020-08-28.
//

#ifndef MST_UF_H
#define MST_UF_H

#include <vector>

class UF {
public:
    UF(int n) : weight(n, 1) {
        for (int i = 0; i < n; ++i)
            id.push_back(i);
    }

    int get_root(int n) {
        if (id[n] == n)
            return n;
        else {
            id[n] = id[id[n]];
            return get_root(id[n]);
        }
    }

    void unite(int p, int q) {
        int rootp = get_root(p);
        int rootq = get_root(q);
        if (rootp == rootq) return;
        if (weight[rootp] < weight[rootq]) {
            id[rootp] = rootq;
            weight[rootq] += weight[rootp];
        } else {
            id[rootq] = rootp;
            weight[rootp] += weight[rootq];
        }
    }

    bool connected(int p, int q) {
        return get_root(p) == get_root(q);
    }

private:
    std::vector<int> id;
    std::vector<int> weight;
};


#endif //MST_UF_H
