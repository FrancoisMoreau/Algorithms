//
// Created by brayden on 2019-09-19.
//

#include "TaxicabNumber.h"

std::ostream &print(std::ostream &out, const TaxicabNumber &tn) {
    out << "(" << tn.a << ", " << tn.b << "), cube sum: "<< tn.cube_sum << "\n";
    return out;
}

void find_taxicab_numbers(int key, std::vector<TaxicabNumber> &resTN) {
    std::priority_queue<long> pq;
    for (int i = 0; i < key; ++i) {
        for (int j = 0; j < key; ++j) {
            TaxicabNumber tn(i, j);
        }
    }
}
