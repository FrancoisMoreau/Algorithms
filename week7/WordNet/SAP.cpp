//
// Created by brayden on 2020-01-18.
//

#include "SAP.h"
#include <queue>

SAP::SAP(Digraph *G) : Graph(G), marked(G->V(), 0), edgeTo(G->V(), -1) {

}

int SAP::ancestor(int v, int w) {
    return sap_anc_leng(v, w).first;
}

int SAP::length(int v, int w) {
    return sap_anc_leng(v, w).second;
}

int SAP::ancestor(const std::vector<int> &v, const std::vector<int> &w) {
    return sap_anc_leng(v, w).first;
}

int SAP::length(const std::vector<int> &v, const std::vector<int> &w) {
    return sap_anc_leng(v, w).second;
}

std::pair<int, int> SAP::sap_anc_leng(int v, int w) {
    if (v == w) return {v, 0};
    std::vector<int> lhs_vec{v}, rhs_vec{w};
    return sap_anc_leng(lhs_vec, rhs_vec);
}

std::pair<int,int> SAP::sap_anc_leng(const std::vector<int> &v, const std::vector<int> &w) {
    marked = std::vector<int>(Graph->V(), 0);
    edgeTo = std::vector<int>(Graph->V(), -1);
    std::queue<int, std::deque<int>> lhs(std::deque<int>(v.begin(), v.end()));
    std::queue<int, std::deque<int>> rhs(std::deque<int>(w.begin(), w.end()));
    int ances = shortest_ancestor(lhs, rhs);
    if (ances == -1)
        return {-1, -1000};
    else
    {
        int lhs_len = shortest_length(v, ances);
        int rhs_len = shortest_length(w, ances);
        return {ances, lhs_len + rhs_len};
    }
}

int SAP::shortest_length(const std::vector<int> &s, int target) {
    marked = std::vector<int>(marked.size(), 0);
    std::queue<int, std::deque<int>> start(std::deque<int>(s.begin(), s.end()));

    marked[start.front()] = true;
    std::vector<size_t> layers{start.size()};
    int count = 0;
    while (!start.empty()) {
        int v = start.front();
        if (v == target) break;
        start.pop();

        if (count++ == 0) layers.push_back(0);
        for (auto w : Graph->get_adj(v)) {
            if (w == target) return layers.size() - 1;
            if (!marked[w]) {
                marked[w] = 1;
                start.push(w);
                layers.back()++;
            }
        }
        if (count == layers[layers.size() - 2]) count = 0;
    }

    return layers.size() - 1;
}

int SAP::shortest_ancestor(std::queue<int> &lhs, std::queue<int> &rhs){
    int lhs_v = 0, rhs_v = 0;
    while (!lhs.empty() && !rhs.empty()) {
        lhs_v = bfs(lhs, 1);
        if (lhs_v != -1) return lhs_v;
        rhs_v = bfs(rhs, 2);
        if (rhs_v != -1) return rhs_v;
    }
    while (!lhs.empty()) {
        lhs_v = bfs(lhs, 1);
        if (lhs_v != -1) return lhs_v;
    }
    while (!rhs.empty()) {
        rhs_v = bfs(rhs, 2);
        if (rhs_v != -1) return rhs_v;
    }
    return -1;
}

int SAP::bfs(std::queue<int> &q, int tag) {
    int v = q.front();
    if (!marked[v]) marked[v] = tag;
    else if (marked[v] != tag) return v;
    q.pop();
    for (auto w : Graph->get_adj(v)) {
        if (!marked[w]) {
            marked[w] = tag;
            q.push(w);
            edgeTo[w] = v;
        } else if (marked[w] != tag) {
            return w;
        }
    }
    return -1;
}
