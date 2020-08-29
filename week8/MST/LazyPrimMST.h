//
// Created by brayden on 2020-08-28.
//

#ifndef MST_LAZYPRIMMST_H
#define MST_LAZYPRIMMST_H

#include <queue>
#include "Edge.h"
#include "Edgeweightedgraph.h"


struct comparator {
    bool operator()(const Edge &lhs, const Edge &rhs) {
        return lhs.get_weight() > rhs.get_weight();
    }
};

class LazyPrimMST {
public:
    LazyPrimMST(Edgeweightedgraph *G) : marked(G->V()) {
        visit(G, 0);
        while (!minpq.empty() && mst.size() < G->V() - 1) {
            Edge e = minpq.top();
            minpq.pop();
            int v = e.either(), w = e.other(v);
            if (marked[v] && marked[w]) continue;
            mst.push(e);
            if (!marked[v]) visit(G, v);
            if (!marked[w]) visit(G, w);
        }
    }

    std::queue<Edge> get_mst() {
        return mst;
    }

private:
    void visit(Edgeweightedgraph *G, int v) {
        marked[v] = true;
        for (Edge &e : G->get_adj(v)) {
            if (!marked[e.other(v)])
                minpq.push(e);
        }
    }
    vector<bool> marked;
    std::queue<Edge> mst;
    std::priority_queue<Edge, std::vector<Edge>, comparator> minpq;
};


#endif //MST_LAZYPRIMMST_H
