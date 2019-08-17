//
// Created by brayden on 2019-08-17.
//

#ifndef INTERVIEWQUESTIONS_UFCANONICAL_H
#define INTERVIEWQUESTIONS_UFCANONICAL_H

#include <vector>

using std::vector;

class UFCanonical {
public:
    UFCanonical(int n);
    int find(int k);
    void unite(int p, int q);
    bool connected(int p, int q);

private:
    vector<int> id;
    vector<int> sz;
    int root(int p);
    void balance_root(int start, int start_root, int final_root);

};


#endif //INTERVIEWQUESTIONS_UFCANONICAL_H
