//
// Created by brayden on 2020-01-06.
//

#ifndef DIRECTEDGRAPH_DIRECTEDDFS_H
#define DIRECTEDGRAPH_DIRECTEDDFS_H

#include "Digraph.h"
#include <stack>


class DirectedDFS {
public:
    DirectedDFS(const Digraph *graph, int s);
    bool visited(int v) const { return marked[v]; }
    std::stack<int> pathto(int v);

private:
    int source = -1;
    std::vector<int> marked;
    std::vector<int> path;
    void dfs(const Digraph *graph, int v);
};


#endif //DIRECTEDGRAPH_DIRECTEDDFS_H
