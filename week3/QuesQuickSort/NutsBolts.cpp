#include "NutsBolts.h"


size_t NB_Partion(std::vector<int> &nuts, std::vector<char> &bolts, int idx, int lo, int hi) {
    int key = nuts[idx];
    int matched_idx = lo;

    for (int m = lo; m <= hi; ++m)
        if (bolts[m] - 'a' == key) matched_idx = m;

    std::swap(bolts[lo], bolts[matched_idx]);

    int i = lo, j = hi + 1;
    while (true) {
        while (bolts[++i]  - 'a' < key)
            if (i > hi) break;

        while (key < bolts[--j] - 'a')
            if (j < lo) break;

        if (i >= j) break;
        std::swap(bolts[i], bolts[j]);
    }
    std::swap(bolts[lo], bolts[j]);
    return j;
}

std::pair<int, int> find_interval(std::vector<int> &nuts, std::vector<char> &bolts, std::vector<size_t> &position, int order) {
    int start = 0, end = bolts.size() - 1;
    for (int i = 0; i < order; ++i) {
        if (nuts[order] < bolts[position[i]] - 'a')
            end = position[i] - 1;
        else
            start = position[i] + 1;
    }
    return {start, end};
}

void NutsBolts(std::vector<int> &nuts, std::vector<char> &bolts, std::vector<size_t> &position) {
    int N = nuts.size() - 1;
    for (int i = 0; i <= N; ++i) {
        std::pair<int, int> interval = find_interval(nuts, bolts, position, i);
        position[i] = NB_Partion(nuts, bolts, i, interval.first, interval.second);

    }

}
