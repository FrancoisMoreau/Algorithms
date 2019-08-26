#include "ThreeWayPartition.h"


void ThreeWayPartition(std::vector<int> &vec) {
    int key = 1;
    int lt = 0, i = 0, gt = vec.size() - 1;
    while (i <= gt) {
        if (vec[i] < key) {
            std::swap(vec[i++], vec[lt++]);
        } else if (vec[i] > key) {
            std::swap(vec[i], vec[gt--]);
        } else {
            ++i;
        }
    }
}

void ThreeWayQuickSort(std::vector<int> &vec, int lo, int hi) {
    if (hi <= lo)
        return ;
    int key = vec[lo];
    int lt = lo, i = lo, gt = hi;
    while (i <= gt) {
        if (vec[i] < key) {
            std::swap(vec[i++], vec[lt++]);
        } else if (vec[i] > key) {
            std::swap(vec[i], vec[gt--]);
        } else {
            ++i;
        }
    }
    ThreeWayQuickSort(vec, lo, lt - 1);
    ThreeWayQuickSort(vec, gt + 1, hi);
}


void ThreeWayQuickSort(std::vector<int> &vec) {
    ThreeWayQuickSort(vec, 0, vec.size() - 1);
}
