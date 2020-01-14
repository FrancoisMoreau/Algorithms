//
// Created by brayden on 2020-01-13.
//

#include "DepthFirstOrder.h"

DepthFirstOrder::DepthFirstOrder(Digraph *G) : marked(G->V(), false) {
    for (int v = 0; v < G->V(); ++v) {
        if (!marked[v])
            dfs(G, v);
    }

}

void DepthFirstOrder::dfs(Digraph *G, int v) {
    marked[v] = true;
    for (auto w : G->get_adj(v)) {
        if (!marked[w]) dfs(G, w);
    }
    reversePost.push(v);
}