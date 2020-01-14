//
// Created by brayden on 2020-01-13.
//

#include "KosarajuSharirSCC.h"

KosarajuSharirSCC::KosarajuSharirSCC(Digraph *G) : marked(G->V(), false), id(G->V(), -1) {
    Digraph reversed = G->reverse();
    DepthFirstOrder dfs_order = DepthFirstOrder(&reversed);
    std::stack<int> reversed_post = dfs_order.get_reversePost();
    while (!reversed_post.empty()) {
        int v = reversed_post.top();
        if (!marked[v]) {
            dfs(G, v);
            count++;
        }
        reversed_post.pop();
    }
    for (int i = 0; i < id.size(); ++i) {
        printf("%d: group: %d\n", i, id[i]);
    }
}

void KosarajuSharirSCC::dfs(Digraph *G, int v) {
    marked[v] = true;
    id[v] = count;
    for (int w : G->get_adj(v)) {
        if (!marked[w]) {
            dfs(G, w);
        }
    }
}