//
// Created by brayden on 2019-10-21.
//

#ifndef UNDIRECTEDGRAPH_BREATHFIRSTPATH_H
#define UNDIRECTEDGRAPH_BREATHFIRSTPATH_H

#include <vector>
#include <stack>
#include "Udgraph.h"

class BreathFirstPath {
public:
    BreathFirstPath(Udgraph *G, int s);
    bool hasPathTo(int v) { return marked[v]; }
    std::stack<int> pathTo(int v);
private:
    void bfs(Udgraph *G, int s);
    int s;
    std::vector<int> edgeTo;
    std::vector<bool> marked;

};


#endif //UNDIRECTEDGRAPH_BREATHFIRSTPATH_H
