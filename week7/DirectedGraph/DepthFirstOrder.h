//
// Created by brayden on 2020-01-13.
//

#ifndef DIRECTEDGRAPH_DEPTHFIRSTORDER_H
#define DIRECTEDGRAPH_DEPTHFIRSTORDER_H

#include "Digraph.h"
#include "stack"

class DepthFirstOrder {
public:
    DepthFirstOrder(Digraph *G);
    std::stack<int> get_reversePost() { return reversePost; }

private:
    void dfs(Digraph *G, int v);
    std::vector<bool> marked;
    std::stack<int> reversePost;
};


#endif //DIRECTEDGRAPH_DEPTHFIRSTORDER_H
