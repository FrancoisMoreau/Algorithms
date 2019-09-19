//
// Created by brayden on 2019-09-19.
//

#ifndef QUESTIONPQ_TAXICABNUMBER_H
#define QUESTIONPQ_TAXICABNUMBER_H

#include <iostream>
#include <vector>
#include <queue>

class TaxicabNumber;

std::ostream &print(std::ostream &out, const TaxicabNumber &lhs, const TaxicabNumber &rhs);
bool operator<(const TaxicabNumber &lhs, const TaxicabNumber &rhs);
bool operator==(const TaxicabNumber &lhs, const TaxicabNumber &rhs);

class TaxicabNumber {
    friend bool operator<(const TaxicabNumber &lhs, const TaxicabNumber &rhs);
    friend bool operator==(const TaxicabNumber &lhs, const TaxicabNumber &rhs);
public:
    TaxicabNumber(int a, int b) : a(a), b(b), cube_sum(a * a * a + b * b * b) {}
    TaxicabNumber(const TaxicabNumber &rhs) : a(rhs.a), b(rhs.b), cube_sum(rhs.cube_sum) {}
    TaxicabNumber &operator=(const TaxicabNumber &rhs);
    int a, b;
    int cube_sum;
};

void find_taxicab_numbers(int key, std::vector<TaxicabNumber> &resTN);


#endif //QUESTIONPQ_TAXICABNUMBER_H
