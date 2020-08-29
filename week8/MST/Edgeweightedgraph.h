//
// Created by brayden on 2020-08-28.
//

#ifndef MST_EDGEWEIGHTEDGRAPH_H
#define MST_EDGEWEIGHTEDGRAPH_H

#include <vector>
#include <iostream>
#include "Edge.h"

using std::vector;


class Edgeweightedgraph {
public:
    Edgeweightedgraph(int V) : adj(V) {}
    Edgeweightedgraph(std::istream &in) {
        int v = 0, w = 0;
        double weight = 0;
        int vertices = 0, edges = 0;
        in >> vertices >> edges;
        adj = std::vector<vector<Edge>>(vertices);

        while (in) {
            in >> v >> w >> weight;
            Edge e(v, w, weight);
            addEdge(e);
        }
    }

    void addEdge(const Edge &e) {
        int v = e.either();
        int w = e.other(v);
        adj[v].push_back(e);
        adj[w].push_back(e);
    }

    vector<Edge> get_edges() {
        vector<Edge> res;
        for (int i = 0; i < adj.size(); ++i) {
            for (Edge &e : adj[i]) {
                if (e.other(i) > i)
                    res.push_back(e);
            }
        }
        return res;
    }

    int V() {
        return adj.size();
    }


    vector<Edge> get_adj(int v) {
        return adj[v];
    }

private:
    vector<vector<Edge>> adj;

};


#endif //MST_EDGEWEIGHTEDGRAPH_H
