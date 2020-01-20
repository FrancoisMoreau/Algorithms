//
// Created by brayden on 2020-01-18.
//

#include "Digraph.h"


Digraph::Digraph(std::istream &is) {
    int vertices, edge, v = 0, w = 0;
    is >> vertices >> edge;
    adj = std::vector<std::vector<int>>(vertices);
    while (is) {
        is >> v >> w;
        addEdge(v, w);
    }
}

Digraph Digraph::reverse() {
    Digraph reversed(V());
    for (int i = 0; i < adj.size(); ++i) {
        for (auto j : adj[i]) {
            reversed.addEdge(j, i);
        }
    }
    return reversed;
}