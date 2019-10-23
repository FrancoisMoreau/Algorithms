//
// Created by brayden on 2019-10-20.
//

#ifndef UNDIRECTEDGRAPH_UDGRAPH_H
#define UNDIRECTEDGRAPH_UDGRAPH_H

#include <vector>
#include <string>
#include <iostream>

class Udgraph {
public:
    Udgraph() = default;
    Udgraph(int V) : adj_list(V) {}
    Udgraph(std::istream &in);
    void addEdge(int v, int w);
    int V() { return adj_list.size(); }
    int E() { return edges; };
    std::string toString();
    std::vector<int> &adj(int v) { return adj_list[v]; }

private:
    std::vector<std::vector<int>> adj_list;
    int edges = 0;

};


#endif //UNDIRECTEDGRAPH_UDGRAPH_H
