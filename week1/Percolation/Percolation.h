//
// Created by brayden on 2019-08-11.
//

#ifndef PERCOLATION_PERCOLATION_H
#define PERCOLATION_PERCOLATION_H

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Percolation {
public:
    Percolation(int n);
    void open(int row, int col);
    bool isOpen(int row, int col) const;
    bool isFull(int row, int col) const;
    int numberOfOpenSites() const;
    bool percolates() const;

private:
    int N;
    mutable vector<int> id;
    vector<int> sz;
    vector<bool> status;
    int NumOpen;
    void check(int idx, const string &msg) const;
    void check(int row, int col) const;
    int root(int i) const;
    bool connected(int p, int q) const;
    void unite(int p, int q);
    void connect_site(int lhs_row, int lhs_col, int rhs_row, int rhs_col);
    void connect_neighbors(int row, int col);
};


#endif //PERCOLATION_PERCOLATION_H
