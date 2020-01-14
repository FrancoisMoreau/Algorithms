//
// Created by brayden on 2020-01-06.
//

#include "DirectedDFS.h"
#include <stack>
#include <exception>

DirectedDFS::DirectedDFS(const Digraph *graph, int s) :
    source(s), marked(graph->V(), false), path(graph->V(), -1) {
//    marked[s] = true;
    dfs(graph, s);
}

void DirectedDFS::dfs(const Digraph *graph, int v) {
    marked[v] = true;
    for (auto &w : graph->get_adj(v)) {
        if (!marked[w]) {
            path[w] = v;
//            marked[w] = true;
            dfs(graph, w);
        }
    }
}

std::stack<int> DirectedDFS::pathto(int v) {
    if (!marked[v]) {
        throw std::out_of_range("Vertex  cannot be accessed by this source!\n");
    }
    std::stack<int> stk;
    for (auto x = v; x != source; x = path[x]) {
        stk.push(x);
    }
    stk.push(source);
    return stk;
}