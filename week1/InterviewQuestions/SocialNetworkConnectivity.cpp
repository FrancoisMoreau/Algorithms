//
// Created by brayden on 2019-08-15.
//

#include "SocialNetworkConnectivity.h"


SocialNetCon::SocialNetCon(int n) :
    sz(std::move(vector<int>(n, 1))), count(n), allconnected(false) {
    for (int i = 0; i < n ; ++i) {
        id.push_back(i);
    }
}

int SocialNetCon::root(int p) {
    if (p == id[p])
        return p;
    else {
        id[p] = id[id[p]];
        return root(id[p]);
    }
}

bool SocialNetCon::connected(int p, int q) {
    if (root(p) == root(q))
        return true;
    else
        return false;
}

void SocialNetCon::unite(int p, int q) {
    int p_root = root(p);
    int q_root = root(q);
    if (sz[p_root] < sz[q_root]) {
        id[p_root] = q_root;
        sz[q_root] += sz[p_root];
        if (sz[q_root] == count)
            allconnected = true;
    } else {
        id[q_root] = p_root;
        sz[p_root] += sz[q_root];
        if (sz[p_root] == count)
            allconnected = true;
    }
}

bool SocialNetCon::linkPair(int p, int q) {
    if (connected(p, q))
        return allconnected;
    else {
        unite(p, q);
        return allconnected;
    }
}