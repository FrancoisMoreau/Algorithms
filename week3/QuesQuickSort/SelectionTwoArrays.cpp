#include "SelectionTwoArrays.h"

int selectionTwoSortedArrays(std::vector<int>::const_iterator it0,
        std::vector<int>::const_iterator it1, int size_0, int size_1, int kth) {
    if (size_0 > size_1) return selectionTwoSortedArrays(it1, it0, size_1, size_0, kth);
    if (size_0 == 0) return *(it1 + kth - 1);
    if (kth == 1) return std::min(*it0, *it1);

    int stride0 = std::min(kth / 2, size_0);
    int stride1 = kth - stride0;
    if (*(it0 + stride0 - 1) == *(it1 + stride1 - 1)) {
        return *(it0 + stride0);
    } else if (*(it0 + stride0 - 1) < *(it1 + stride1 - 1)) {
        return selectionTwoSortedArrays(it0 + stride0, it1, size_0 - stride0, size_1, kth - stride0);
    } else {
        return selectionTwoSortedArrays(it0, it1 + stride1, size_0, size_1 - stride1, kth - stride1);
    }
}


int selectionTwoSortedArrays(std::vector<int> &vec0, std::vector<int> &vec1, int kth) {
    int size_0 = vec0.size();
    int size_1 = vec1.size();

    std::vector<int>::const_iterator it0 = vec0.cbegin(), it1 = vec1.cbegin();

    return selectionTwoSortedArrays(it0, it1, size_0, size_1, kth);
}
