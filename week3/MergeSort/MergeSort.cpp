#include "MergeSort.h"
#include <algorithm>


void merge(std::vector<int> &v, std::vector<int> &v_helper, int lo, int mid, int hi) {
	std::copy(v.begin() + lo, v.begin() + hi + 1, v_helper.begin() + lo);
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; ++k) {
		if (i > mid) v[k] = v_helper[j++];
		else if (j > hi) v[k] = v_helper[i++];
		else if (v_helper[i] <= v_helper[j]) v[k] = v_helper[i++];
		else v[k] = v_helper[j++];
	}
}

void MergeSort(std::vector<int> &vec, std::vector<int> &v_helper, int lo, int hi) {
    if (hi <= lo)
        return ;
    int mid = lo + (hi - lo) /2;
    MergeSort(vec, v_helper, lo, mid);
    MergeSort(vec, v_helper, mid + 1, hi);
    merge(vec, v_helper, lo, mid, hi);

}

void MergeSort(std::vector<int> &v) {
	int lo = 0, hi = v.size() - 1;
	std::vector<int> v_helper(v.size());
	MergeSort(v, v_helper, lo, hi);
}

void BUMergeSort(std::vector<int> &v) {
    int N = v.size();
    std::vector<int> v_help(N);
    for (int sz = 1; sz < N; sz = sz + sz) {
        for (int lo = 0; lo < N - sz; lo += sz + sz) {
            merge(v, v_help, lo, lo + sz - 1, std::min(lo + sz +sz - 1, N - 1));
        }
    }
}
