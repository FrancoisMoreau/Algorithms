//
// Created by brayden on 2019-10-21.
//

#include "DepthFirstPath.h"
#include <stack>

DepthFirstPath::DepthFirstPath(Udgraph *G, int s) :
    edgeTo(G->V(), -1), marked(G->V(), false), s(s) {
    non_recursive_dfs(G, s);
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

void DepthFirstPath::non_recursive_dfs(Udgraph *G, int v) {
    std::stack<int> stk;
    stk.push(v);
    int last = v;
    while (!stk.empty()) {
        int next = stk.top();
        stk.pop();
        if (!marked[next]) {
            marked[next] = true;
            edgeTo[next] = last;
            last = next;
            for (auto &w : G->adj(next)) {
                if (!marked[w])
                    stk.push(w);
            }
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