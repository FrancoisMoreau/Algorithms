//
// Created by brayden on 2020-08-28.
//

#ifndef MST_KRUSKALMST_H
#define MST_KRUSKALMST_H

#include <queue>
#include "UF.h"
#include "Edge.h"
#include "Edgeweightedgraph.h"

class KruskalMST {
public:
    KruskalMST(Edgeweightedgraph *G) {
        auto cmp = [](const Edge &lhs, const Edge &rhs) {
            return lhs.get_weight() > rhs.get_weight();
        };
        std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> minpq(cmp);
        for (auto e : G->get_edges()) {
            minpq.push(e);
        }
        UF uf(G->V());
        while (!minpq.empty() && mst.size() < G->V() - 1) {
            Edge e = minpq.top();
            minpq.pop();
            int v = e.either(), w = e.other(v);
            if (!uf.connected(v, w)) {
                uf.unite(v, w);
                mst.push(e);
            }
        }
    }

    std::queue<Edge> edges() {
        return mst;
    }

private:
    std::queue<Edge> mst;

};


#endif //MST_KRUSKALMST_H
