//
// Created by brayden on 2019-10-20.
//

#include "Udgraph.h"
#include <sstream>

Udgraph::Udgraph(std::istream &in) {
    int vertices, edges, v = 0, w = 0;
    in >> vertices >> edges;
    adj_list = std::vector<std::vector<int>>(vertices);
    std::string line;
    while(in) {
        in >> v >> w;
        addEdge(v, w);
    }
}

void Udgraph::addEdge(int v, int w) {
    adj_list[v].push_back(w);
    adj_list[w].push_back(v);
    edges++;
}

std::string Udgraph::toString() {
    std::ostringstream res;
    for (int i = 0; i < adj_list.size(); ++i) {
        for (int j = 0; j < adj_list[i].size(); ++j) {
            res << i << " - " <<  adj_list[i][j] << "\n";
        }
    }
    return res.str();
}