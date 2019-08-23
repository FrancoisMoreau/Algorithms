//
// Created by brayden on 2019-08-23.
//

#ifndef ELEMENTARYSORTS_INSERTIONSORT_H
#define ELEMENTARYSORTS_INSERTIONSORT_H

#include <vector>

template <typename T>
void InsertionSort(std::vector<T> &vec) {
    int N = vec.size();
    for (size_t i = 0; i != N; ++i) {
        for (size_t j = i; j != 0; --j) {
            if (vec[j] < vec[j - 1])
                std::swap(vec[j], vec[j - 1]);
            else
                break;
        }
    }
}

#endif //ELEMENTARYSORTS_INSERTIONSORT_H
