#include "QuickSelect.h"


int QuickSelectPartition(std::vector<int> &vec, int lo, int hi) {
    int i = lo, j = hi + 1;
    while (true) {
        while (vec[++i] < vec[lo])
            if (hi <= i) break;

        while (vec[lo] < vec[--j]);

        if (j <= i) break;
        std::swap(vec[i], vec[j]);
    }
    std::swap(vec[lo], vec[j]);
    return j;
}


int QuickSelect(std::vector<int> &vec, int k) {
    int lo = 0, hi = vec.size() - 1;
    while (hi > lo) {
        int j  = QuickSelectPartition(vec, lo, hi);
        if (j < k) lo = j + 1;
        else if (j > k) hi = j - 1;
        else return vec[j];
    }
    return vec[k];
}
