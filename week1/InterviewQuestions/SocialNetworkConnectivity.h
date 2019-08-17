//
// Created by brayden on 2019-08-15.
//

#ifndef INTERVIEWQUESTIONS_SOCIALNETWORKCONNECTIVITY_H
#define INTERVIEWQUESTIONS_SOCIALNETWORKCONNECTIVITY_H

#include <vector>

using std::vector;

class SocialNetCon {
public:
    SocialNetCon(int n);
    bool linkPair(int p, int q);

private:
    vector<int> id;
    vector<int> sz;
    int count;
    bool allconnected;
    int root(int p);
    bool connected(int p, int q);
    void unite(int p, int q);

};


#endif //INTERVIEWQUESTIONS_SOCIALNETWORKCONNECTIVITY_H
