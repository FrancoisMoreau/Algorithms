//
// Created by brayden on 2019-09-19.
//

#include "TaxicabNumber.h"

std::ostream &print(std::ostream &out, const TaxicabNumber &lhs, const TaxicabNumber &rhs) {
    if (lhs.cube_sum == rhs.cube_sum)
        out << lhs.a << "^3 + " << lhs.b << "^3 = " << rhs.a << "^3 + " << rhs.b << " = " << lhs.cube_sum << "\n";
    else {
        out << lhs.a << "^3 + " << lhs.b << "^3 = " << lhs.cube_sum << "\n";
        out << rhs.a << "^3 + " << rhs.b << "^3 = " << rhs.cube_sum << "\n";
    }
    return out;
}

TaxicabNumber &TaxicabNumber::operator=(const TaxicabNumber &rhs) {
    a = rhs.a;
    b = rhs.b;
    cube_sum = rhs.cube_sum;
    return *this;
}

bool operator<(const TaxicabNumber &lhs, const TaxicabNumber &rhs) {
    return lhs.cube_sum < rhs.cube_sum;
}

bool operator==(const TaxicabNumber &lhs, const TaxicabNumber &rhs) {
    return lhs.cube_sum == rhs.cube_sum;
}

bool Minpq_compareTaxicab(const TaxicabNumber &lhs, const TaxicabNumber &rhs) {
    return rhs < lhs;
}

void find_taxicab_numbers(int key, std::vector<TaxicabNumber> &resTN) {
    std::priority_queue<TaxicabNumber, std::vector<TaxicabNumber>, decltype(Minpq_compareTaxicab)*> pq(Minpq_compareTaxicab);
//    std::priority_queue<TaxicabNumber> pq;
    for (int i = 0; i < key; ++i) {
            TaxicabNumber tn(i, i);
            pq.push(tn);
    }
    int run = 1;
    TaxicabNumber prev(0, 0);
    while (pq.size() > 0) {
        TaxicabNumber curr = pq.top();
        pq.pop();

        if (prev == curr) {
            run ++;
            if (run == 2) {
                print(std::cout, prev, curr);
            }
        } else {
            run = 1;
        }
        prev = curr;
        if (curr.b < key - 1) pq.push(TaxicabNumber(curr.a, curr.b + 1));
    }
}
