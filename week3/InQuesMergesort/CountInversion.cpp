#include "CountInversion.h"




int Count_inversion_merge(std::vector<int> &vec, std::vector<int> &aux, int lo, int mid, int hi) {
    std::copy(vec.begin() + lo, vec.begin() + hi + 1, aux.begin() + lo);

    int counts = 0, counts_over = 0;
    int i = lo, j = lo, k = mid + 1;
    while (i <= hi) {
        if (j > mid) vec[i++] = aux[k++];
        else if (k > hi) {
            vec[i++] = aux[j++];
            counts_over += counts ;
        } else if (aux[j] <= aux[k]) {
            vec[i++] = aux[j++];
        } else {
            vec[i++] = aux[k++];
            counts += 1;
        }
    }
    counts = counts_over + counts - counts;
    return counts;
}

int count_inversion(std::vector<int> &vec, std::vector<int> &aux, int lo, int hi) {
    if (lo >= hi)
        return 0;
    int mid = lo + (hi - lo) / 2;
    int count0 = count_inversion(vec, aux, lo, mid);
    int count1 = count_inversion(vec, aux, mid + 1, hi);
    int count2 = Count_inversion_merge(vec, aux, lo, mid, hi);
    int counts = count0 + count1 + count2;
    return  counts;
}


int count_inversion(std::vector<int> &vec) {
    int lo = 0, hi = vec.size() - 1;
    std::vector<int> aux(vec.size());
    int counts = count_inversion(vec, aux, lo, hi);
    return counts;
}
