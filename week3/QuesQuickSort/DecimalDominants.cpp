//
// Created by brayden on 2019-09-15.
//

#include "DecimalDominants.h"

#include <set>

int decimal_partitioning(std::vector<int> &decimal_vec, int lo, int hi) {
    int i = lo, j = hi + 1;
    int key = decimal_vec[lo];
    while (i <= j) {
        while (decimal_vec[++i] < key)
            if (i >= hi) break;
        while (decimal_vec[--j] > key)
            if (j <= lo) break;

        if (i >= j) break;
        std::swap(decimal_vec[i], decimal_vec[j]);
    }
    std::swap(decimal_vec[lo], decimal_vec[j]);
    return j;
}

int decimal_select(std::vector<int> &decimal_vec, int kth) {
    int lo = 0, hi = decimal_vec.size() - 1;
    while (lo < hi) {
        int par = decimal_partitioning(decimal_vec, lo, hi);
        if (kth < par)
            hi = par - 1;
        else if (par < kth)
            lo = par + 1;
        else
            return decimal_vec[kth];
    }
    return decimal_vec[kth];
}

std::vector<int> DecimalDominants(std::vector<int> &decimal_vec) {
    int size = decimal_vec.size();
    int stride = size / 10;
    int prev = decimal_select(decimal_vec, 0);
    for (int i = 0; i <= size; i += stride) {
        decimal_select(decimal_vec, i);
    }
}

