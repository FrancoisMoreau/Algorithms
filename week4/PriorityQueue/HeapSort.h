//
// Created by brayden on 2019-09-01.
//

#ifndef PRIORITYQUEUE_HEAPSORT_H
#define PRIORITYQUEUE_HEAPSORT_H

#include <vector>

const int shiftnum = -1;

template <typename T>
class heap {
public:
    void heapsort(std::vector<T> &vec);

private:
    void sink(std::vector<T> &vec, int k, int N);

};

template <typename T>
void heap<T>::heapsort(std::vector<T> &vec) {
    int N = vec.size();
    for (int i = N/2; i >= 1; --i) {
        sink(vec, i, N);
    }
    while (N > 1) {
        std::swap(vec[1 + shiftnum], vec[N + shiftnum]);
        sink(vec, 1, --N);
    }
}


template <typename T>
void heap<T>::sink(std::vector<T> &vec, int k, int N) {
    while (2 * k <= N) {
        int lhs = 2 * k;
        if (lhs < N && vec[lhs + 1 + shiftnum] > vec[lhs + shiftnum]) lhs++;
        if (vec[lhs + shiftnum] <= vec[k + shiftnum]) break;
        std::swap(vec[k + shiftnum], vec[lhs + shiftnum]);
        k = lhs;
    }
}



#endif //PRIORITYQUEUE_HEAPSORT_H
