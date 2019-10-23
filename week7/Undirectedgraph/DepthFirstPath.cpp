//
// Created by brayden on 2019-10-21.
//

#include "DepthFirstPath.h"

DepthFirstPath::DepthFirstPath(Udgraph *G, int s) :
    edgeTo(G->V(), -1), marked(G->V(), false), s(s) {
    dfs(G, s);
}

void DepthFirstPath::dfs(Udgraph *G, int v) {
    marked[v] = true;
    for (auto &w : G->adj(v)) {
        if (!marked[w]) {
            dfs(G, w);
            edgeTo[w] = v;
        }
    }
}

std::stack<int> DepthFirstPath::pathTo(int v) {
    if (!hasPathTo(v)) return  std::stack<int>();
    std::stack<int> path;
    for (int x = v; x != s; x = edgeTo[x])
        path.push(x);
    path.push(s);
    return path;
}