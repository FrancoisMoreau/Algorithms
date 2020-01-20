//
// Created by brayden on 2020-01-18.
//

#ifndef WORDNET_SAP_H
#define WORDNET_SAP_H

#include <queue>
#include "WordNet.h"
#include "Digraph.h"

class SAP {
public:
    SAP(Digraph *G);
    int length(int v, int w);
    int ancestor(int v, int w);
    int length(const std::vector<int> &v, const std::vector<int> &w);
    int ancestor(const std::vector<int> &v, const std::vector<int> &w);

private:
    std::pair<int, int> sap_anc_leng(int v, int w);
    std::pair<int, int> sap_anc_leng(const std::vector<int> &v, const std::vector<int> &w);
    int shortest_ancestor(std::queue<int> &lhs, std::queue<int> &rhs);
    int shortest_length(const std::vector<int> &s, int target);
    int bfs(std::queue<int> &s, int tag);
    Digraph *Graph;
    std::vector<int> marked;
    std::vector<int> edgeTo;

};


#endif //WORDNET_SAP_H
