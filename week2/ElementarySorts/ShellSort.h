//
// Created by brayden on 2019-08-24.
//

#ifndef ELEMENTARYSORTS_SHELLSORT_H
#define ELEMENTARYSORTS_SHELLSORT_H

#include <vector>

template <typename T>
void ShellSort(std::vector<T> &vec) {
    int N = vec.size();
    int h = 1;
    while (h < N / 3) h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < N; ++i) {
            for (int j = i; j >= h && vec[j] < vec[j - h]; j -= h)
                std::swap(vec[j], vec[j - h]);
        }
        h /= 3;
    }
}

#endif //ELEMENTARYSORTS_SHELLSORT_H
