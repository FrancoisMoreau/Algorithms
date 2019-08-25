#include "QuickSort.h"

int QuickPartition(std::vector<int> &vec, int lo, int hi) {
    int i = lo, j = hi + 1;
    while (true) {
        while (vec[++i] < vec[lo])
            if (i == hi) break;

        while (vec[lo] < vec[--j])
            if (j == lo) break;

        if (i >= j) break;
        std::swap(vec[i], vec[j]);
    }
    std::swap(vec[lo], vec[j]);
    return j;
}

void QuickSort(std::vector<int> &vec, int lo, int hi) {
    if (hi <= lo)
        return;
    int j = QuickPartition(vec, lo, hi);
    QuickSort(vec, lo, j - 1);
    QuickSort(vec, j + 1, hi);

}

void QuickSort(std::vector<int> &vec) {
    QuickSort(vec, 0, vec.size() - 1);
}