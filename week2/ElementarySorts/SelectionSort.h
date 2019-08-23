//
// Created by brayden on 2019-08-23.
//

#ifndef ELEMENTARYSORTS_SELECTIONSORT_H
#define ELEMENTARYSORTS_SELECTIONSORT_H

#include <vector>

template <typename T>
void SelectionSort(std::vector<T> &vec) {
    int N = vec.size();
    for (size_t i = 0; i != N; ++i) {
        int min_idx = i;
        for (size_t j = i + 1; j != N; ++j) {
            min_idx = vec[j] < vec[min_idx] ? j : min_idx;
        }
        std::swap(vec[min_idx], vec[i]);
    }
}

#endif //ELEMENTARYSORTS_SELECTIONSORT_H
