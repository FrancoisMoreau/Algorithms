//
// Created by brayden on 2019-08-10.
//

#ifndef UNIONFIND_QUICKUNION_H
#define UNIONFIND_QUICKUNION_H

#include <vector>

using std::vector;

class QuickUnion {
private:
    vector<int> id;
    int get_root(int n);

public:
    QuickUnion(int N);
    bool connected(int p, int q);
    void unite(int p, int q);

};


#endif //UNIONFIND_QUICKUNION_H
