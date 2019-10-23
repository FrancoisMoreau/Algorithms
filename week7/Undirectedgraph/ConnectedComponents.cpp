//
// Created by brayden on 2019-10-21.
//

#include "ConnectedComponents.h"

void ConnectedComponents::dfs(Udgraph &G, int v) {
    marked[v] = true;
    id[v] = count;
    for (auto &w : G.adj(v)) {
        if (!marked[w])
            dfs(G, w);
    }
}

ConnectedComponents::ConnectedComponents(Udgraph &G): marked(G.V(), false), id(G.V(), -1) {
    for (int v = 0; v < G.V(); ++v) {
        if (!marked[v]) {
            dfs(G, v);
            count++;
        }
    }
}