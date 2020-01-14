//
// Created by brayden on 2020-01-13.
//

#ifndef DIRECTEDGRAPH_KOSARAJUSHARIRSCC_H
#define DIRECTEDGRAPH_KOSARAJUSHARIRSCC_H

#include "Digraph.h"
#include "DepthFirstOrder.h"

class KosarajuSharirSCC {
public:
    KosarajuSharirSCC(Digraph *G);

private:
    void dfs(Digraph *G, int v);
    std::vector<bool> marked;
    std::vector<int> id;
    int count = 0;

};


#endif //DIRECTEDGRAPH_KOSARAJUSHARIRSCC_H
