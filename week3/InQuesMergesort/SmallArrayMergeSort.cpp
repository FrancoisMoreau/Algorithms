#include "SmallArrayMergeSort.h"


void Merge(std::vector<int> &vec, std::vector<int> &aux, int lo, int mid, int hi) {
    std::copy(vec.cbegin() + lo, vec.cbegin() + hi + 1, aux.begin() + lo);

    int i = lo, j = lo, k = mid + 1;
    while (i <= hi) {
        if (j > mid) vec[i++] = aux[k++];
        else if (k > hi) vec[i++] = aux[j++];
        else if (aux[j] <= aux[k]) vec[i++] = aux[j++];
        else vec[i++] = aux[k++];
    }
}

void SmallMS(std::vector<int> &vec, std::vector<int> &aux, int lo, int hi) {
    if (lo >= hi)
        return;
    int mid = lo + (hi - lo) / 2;
    SmallMS(vec, aux, lo, mid);
    SmallMS(vec, aux, mid + 1, hi);
    Merge(vec, aux, lo, mid, hi);
}

void SmallMS(std::vector<int> &vec) {
    int lo = 0, hi = vec.size() - 1;
    std::vector<int> aux(vec.size());
    SmallMS(vec, aux, lo, hi);
}
