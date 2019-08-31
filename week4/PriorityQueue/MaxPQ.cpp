//
// Created by brayden on 2019-08-31.
//

#include "MaxPQ.h"

void MaxPQ::insert(int val) {
    keys.push_back(val);
    ++N;
    swim(N);
}

void MaxPQ::swim(int k) {
    while (k > 1 && keys[k/2] < keys[k]) {
        std::swap(keys[k/2], keys[k]);
        k /= 2;
    }
}

void MaxPQ::sink(int k) {
    while (2 * k <= N ) {
        int j = 2 * k;
        if (j < N && keys[j] < keys[j + 1]) ++j;
        if (keys[j] <= keys[k]) break;
        std::swap(keys[k], keys[j]);
        k = j;
    }
}

int MaxPQ::delMax() {
    if (isEmpty())
        throw std::out_of_range("cannot delete on an empty tree");
    int max = keys[1];
    std::swap(keys[1], keys[N--]);
    sink(1);
    keys.pop_back();
    return max;
}