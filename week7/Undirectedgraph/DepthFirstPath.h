//
// Created by brayden on 2019-10-21.
//

#ifndef UNDIRECTEDGRAPH_DEPTHFIRSTPATH_H
#define UNDIRECTEDGRAPH_DEPTHFIRSTPATH_H

#include "Udgraph.h"
#include "stack"

class DepthFirstPath {
public:
    DepthFirstPath(Udgraph *G, int s);
    bool hasPathTo(int v) { return marked[v]; }
    std::stack<int> pathTo(int v);

private:
    void dfs(Udgraph *G, int v);
    int s;
    std::vector<int> edgeTo;
    std::vector<bool> marked;

};


#endif //UNDIRECTEDGRAPH_DEPTHFIRSTPATH_H
