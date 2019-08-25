#include "FastMergeSort.h"

void InsertionSort(std::vector<int>::iterator a, int lo, int hi) {
    for (int i = lo; i != hi; ++i) {
        for (int j = i + 1; j != lo; --j) {
            if (*(a + j) < *(a + j - 1))
                std::swap(*(a + j), *(a + j - 1));
            else
                break;
        }
    }
}

void FastMerge(std::vector<int> &vec, std::vector<int> &vec_help, int lo, int mid, int hi) {
//    std::copy(vec.begin() + lo, vec.begin() + hi + 1, vec_help.begin() + lo);

    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
        if (mid < i) vec_help[k] = vec[j++];
        else if (hi < j) vec_help[k] = vec[i++];
        else if (vec[i] < vec[j]) vec_help[k] = vec[i++];
        else vec_help[k] = vec[j++];
    }
}

void FastMergeSort(std::vector<int> &vec, std::vector<int> &vec_help, int lo, int hi) {
    if (hi <= lo)
        return ;
//    if (hi <= lo + 7 - 1) {
//        InsertionSort(vec.begin(), lo, hi);
//        return;
//    }
    int mid = lo + (hi - lo) / 2;
    FastMergeSort(vec_help, vec, lo, mid);
    FastMergeSort(vec_help, vec, mid + 1, hi);
//    if (vec[mid] < vec[mid + 1])
//        return;
    FastMerge(vec, vec_help, lo, mid, hi);
}

void FastMergeSort(std::vector<int> &vec) {
    std::vector<int> vec_help = vec;
    FastMergeSort(vec, vec_help, 0, vec.size() - 1);
    vec = vec_help;
}