//
// Created by brayden on 2019-08-29.
//

#include "Permutation.h"

bool IsPermutation(std::vector<int> lhs, std::vector<int> rhs) {
    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());
    auto n = lhs.size();
    for (auto i = 0; i < n; ++i) {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}