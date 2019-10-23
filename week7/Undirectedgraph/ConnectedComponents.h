//
// Created by brayden on 2019-10-21.
//

#ifndef UNDIRECTEDGRAPH_CONNECTEDCOMPONENTS_H
#define UNDIRECTEDGRAPH_CONNECTEDCOMPONENTS_H

#include <vector>
#include "Udgraph.h"

class ConnectedComponents {
public:
    ConnectedComponents(Udgraph &G);
    bool connected(int v, int w) { return id[v] == id[w]; };
    int get_count() { return count; };
    int get_id(int v) { return id[v]; };

private:
    void dfs(Udgraph &G, int v);
    std::vector<bool> marked;
    std::vector<int> id;
    int count = 0;

};


#endif //UNDIRECTEDGRAPH_CONNECTEDCOMPONENTS_H
