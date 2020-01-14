//
// Created by brayden on 2020-01-06.
//

#ifndef DIRECTEDGRAPH_DIGRAPH_H
#define DIRECTEDGRAPH_DIGRAPH_H

#include <vector>
#include <iostream>


class Digraph {
public:
    Digraph(int V) : adj(V) { }
    Digraph(std::istream &is);
    int V() const { return adj.size(); }
    int E() const { return edges; }
    const std::vector<int> &get_adj(int v) const { return adj[v]; }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        ++edges;
    }
    Digraph reverse();

private:
    int edges = 0;
    std::vector<std::vector<int>> adj;
};


#endif //DIRECTEDGRAPH_DIGRAPH_H
