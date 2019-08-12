//
// Created by brayden on 2019-08-11.
//

#ifndef UNIONFIND_WEIGHTEDQUICKUNION_H
#define UNIONFIND_WEIGHTEDQUICKUNION_H


#include <vector>

using std::vector;

class WeightedQuickUnion {
private:
    vector<int> id;
    vector<int> sz;
    int get_root(int n);

public:
    WeightedQuickUnion(int N);
    bool connected(int p, int q);
    void unite(int p, int q);

};


#endif //UNIONFIND_WEIGHTEDQUICKUNION_H
