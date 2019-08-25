#include "FastQuickSort.h"

void InsertionSort(std::vector<int> &vec, int lo, int hi) {
    for (int i = lo; i < hi; ++i) {
        for (int j = i + 1; j != lo; --j) {
            if (vec[j] < vec[j-1])
                std::swap(vec[j], vec[j- 1]);
            else
                break;
        }
    }
}

int FastQuickSortPartition(std::vector<int> &vec, int lo, int hi) {
    int i = lo, j = hi + 1;
    while (true) {
        while (vec[++i] < vec[lo])
            if (i == hi) break;

        while (vec[lo] < vec[--j]);

        if (i >= j) break;
        std::swap(vec[i], vec[j]);
    }
    std::swap(vec[lo], vec[j]);
    return j;
}

int get_midianof3(std::vector<int> &vec, int lo, int mid, int hi) {
    int a = vec[lo], b = vec[mid], c = vec[hi];
    if (a < b) {
        if (b < c)
            return mid;
        else
            return a < c ? hi : lo;
    } else {
        if (b < c)
            return a < c ? lo : hi;
        else
            return mid;
    }
}

void FastQuickSort(std::vector<int> &vec, int lo, int hi) {
    if (hi < lo + 9) {
        InsertionSort(vec, lo, hi);
        return;
    }
//    if (hi <= lo)
//        return;

//    int mid = get_midianof3(vec, lo, (lo + hi)/2, hi);
//    std::swap(vec[lo], vec[mid]);

    int j = FastQuickSortPartition(vec, lo, hi);
    FastQuickSort(vec, lo, j - 1);
    FastQuickSort(vec, j + 1, hi);
}

void FastQuickSort(std::vector<int> &vec) {
    FastQuickSort(vec, 0, vec.size() - 1);
}