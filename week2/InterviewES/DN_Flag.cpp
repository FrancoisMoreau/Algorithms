//
// Created by brayden on 2019-08-29.
//

#include "DN_Flag.h"

void DN_Flag(std::vector<int> &vec) {
    int lo = 0, hi = vec.size() - 1;
    int i = lo, lt = lo, gt = hi;

    int key = 1;

    while (i <= gt) {
        if (vec[i] < key) std::swap(vec[i++], vec[lt++]);
        else if (vec[i] > key ) std::swap(vec[i], vec[gt--]);
        else ++i;
    }
}