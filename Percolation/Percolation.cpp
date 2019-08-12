//
// Created by brayden on 2019-08-11.
//

#include "Percolation.h"

//initialization order corresponds to the order of members in the class
//suggest not use N to initialize sz/status
Percolation::Percolation(int n): N(n + 1), NumOpen(0),
        sz(std::move(vector<int>(N * N, 1))),
        status(std::move(vector<bool>(N * N, false))) {
    int size = N * N;
    for (int i = 0; i != size; ++i) {
        id.push_back(i);
    }
    //virtual site which is connected to the top/bottom row
    for (int i = 1; i != N; ++i) {
        unite(0, N + i);
        unite(size - N, size - N + i);
    }
}

void Percolation::check(int idx, const string &msg) const {
    if (idx <= 0 || idx > N)
        throw std::out_of_range(msg);
}

void Percolation::check(int row, int col) const {
    check(row, "Row number exceeded");
    check(col, "Col number exceeded");
}

int Percolation::root(int i) const {
    if (i == id[i])
        return i;
    else {
        id[i] = id[id[i]];
        return root(id[i]);
    }
}

bool Percolation::connected(int p, int q) const {
    if (root(p) == root(q))
        return true;
    else
        return false;
}

void Percolation::unite(int p, int q) {
    int p_root = root(p);
    int q_root = root(q);
    if (sz[p_root] < sz[q_root]) {
        id[p_root] = q_root;
        sz[q_root] += sz[p_root];
    } else {
        id[q_root] = p_root;
        sz[p_root] += sz[q_root];
    }
}



void Percolation::connect_site(int lhs_row, int lhs_col, int rhs_row, int rhs_col) {
    int p = lhs_row * N + lhs_col;
    int q = rhs_row * N + rhs_col;
    if (!connected(p, q)) {
        unite(p, q);
    }
}

bool Percolation::isOpen(int row, int col) const {
    check(row, col);
    return status[N * row + col];
}

void Percolation::connect_neighbors(int row, int col) {
    if (row > 1 && isOpen(row -1, col))
        connect_site(row - 1, col, row, col);
    if (col > 1 && isOpen(row, col - 1))
        connect_site(row, col - 1, row, col);
    if (row < N && isOpen(row + 1, col))
        connect_site(row + 1, col, row, col);
    if (col < N && isOpen(row, col + 1))
        connect_site(row, col + 1, row, col);
}

void Percolation::open(int row, int col) {
    check(row, col);
    if (isOpen(row, col))
        return;
    status[N * row + col] = true;
    NumOpen += 1;
    connect_neighbors(row, col);
}

bool Percolation::isFull(int row, int col) const {
    check(row, col);
    if (!isOpen(row, col))
        return false;
    int idx = row * N + col;
    if (connected(0, idx))
        return true;
    else
        return false;
}

int Percolation::numberOfOpenSites() const {
    return NumOpen;
}

bool Percolation::percolates() const {
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            std::cout << id[i * N + j] << " ";
//        }
//        std::cout << std::endl;
//    }
    if (connected(0, N * N - N))
        return true;
    else
        return false;
}

