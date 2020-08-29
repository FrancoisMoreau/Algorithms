//
// Created by brayden on 2020-04-21.
//

#ifndef TRIES_RWAYTRIE_H
#define TRIES_RWAYTRIE_H

#include <string>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;

template <typename T, unsigned N>
class RwayTrie {
public:
    RwayTrie() = default;
    void put(string key, T val) { root = put(root, key, val, 0); }
    T get(string key) {
        shared_ptr<Node> x = get(root, key, 0);
        if (!x || !x->val) throw std::out_of_range("No key found!");
        return *(x->val);
    }
//    void remove(string key);
private:
    struct Node {
        shared_ptr<T> val;
        vector<shared_ptr<Node>> next = vector<shared_ptr<Node>>(N);
    };
    shared_ptr<Node> root = std::make_shared<Node>();
    shared_ptr<Node> put(shared_ptr<Node> x, string key, T val, int d);
    shared_ptr<Node> get(shared_ptr<Node> x, string key, int d);
};

template <typename T, unsigned N>
shared_ptr<typename RwayTrie<T, N>::Node>
RwayTrie<T, N>::put(shared_ptr<RwayTrie<T, N>::Node> x, string key, T val, int d) {
    if (!x) x = std::make_shared<Node>();
    if (d == key.size()) {
        x->val = std::make_shared<T>(val);
        return x;
    }
    size_t idx = key[d] - 'a';
    x->next[idx] = put(x->next[idx], key, val, d + 1);
    return x;
}

template <typename T, unsigned N>
shared_ptr<typename RwayTrie<T, N>::Node>
RwayTrie<T, N>::get(shared_ptr<RwayTrie<T, N>::Node> x, string key, int d) {
    if (!x) return nullptr;
    if (d == key.size()) return x;
    size_t idx = key[d] - 'a';
    return get(x->next[idx], key, d + 1);
}



#endif //TRIES_RWAYTRIE_H
