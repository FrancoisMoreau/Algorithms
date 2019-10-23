//
// Created by brayden on 2019-10-21.
//

#include "BreathFirstPath.h"
#include <queue>

BreathFirstPath::BreathFirstPath(Udgraph *G, int s) : edgeTo(G->V()), marked(G->V()), s(s) {
    bfs(G, s);
}

void BreathFirstPath::bfs(Udgraph *G, int s) {
    std::queue<int> q;
    q.push(s);
    marked[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &w : G->adj(v)) {
            if (!marked[w]) {
                q.push(w);
                marked[w] = true;
                edgeTo[w] = v;
            }
        }
    }
}


std::stack<int> BreathFirstPath::pathTo(int v) {
    if (!hasPathTo(v)) return  std::stack<int>();
    std::stack<int> path;
    for (int x = v; x != s; x = edgeTo[x])
        path.push(x);
    path.push(s);
    return path;
}