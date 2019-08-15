//
// Created by brayden on 2019-08-10.
//

#ifndef UNIONFIND_QUICKFIND_H
#define UNIONFIND_QUICKFIND_H

#include <vector>

using std::vector;

class QuickFind {
private:
    vector<int> id;
public:
    QuickFind(int N);
    bool connected(int p, int q);
    void unite(int p, int q);
};

#endif //UNIONFIND_QUICKFIND_H
