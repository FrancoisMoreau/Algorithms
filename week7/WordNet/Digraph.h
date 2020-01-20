//
// Created by brayden on 2020-01-18.
//

#ifndef WORDNET_DIGRAPH_H
#define WORDNET_DIGRAPH_H

#include <iostream>
#include <vector>

class Digraph {
public:
    Digraph() = default;
    Digraph(int V) : adj(V) { }
    Digraph(std::istream &is);
    int V() const { return adj.size(); }
    const std::vector<int> &get_adj(int v) const { return adj[v]; }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    Digraph reverse();

protected:
    std::vector<std::vector<int>> adj;
};


#endif //WORDNET_DIGRAPH_H
