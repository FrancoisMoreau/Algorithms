//
// Created by brayden on 2019-09-03.
//

#ifndef BINARYST_BINARYST_H
#define BINARYST_BINARYST_H

#include <memory>


template <typename Key, typename Value>
class BST {
public:
    void put(Key key, Value val);
    Value get(Key key);
    Key min();
    Key max();
    void erase(Key key);
    Key floor(Key key);
    Key ceiling(Key key);
    int size() { return size(root); };
    int rank(Key key) { return rank(root, key); };
    

private:
    struct Node {
        Key key;
        Value val;
        int count;
        std::shared_ptr<Node> left, right;
        Node(Key key, Value val, int count) : key(key), val(val), count(count) {}
    };
    std::shared_ptr<Node> root;
    std::shared_ptr<Node> put(std::shared_ptr<Node> x, Key key, Value val);
    std::shared_ptr<Node> floor(std::shared_ptr<Node> x, Key key);
    int size(std::shared_ptr<Node> x);
    int rank(std::shared_ptr<Node> x, Key key);

};

template <typename Key, typename Value>
Value BST<Key, Value>::get(Key key) {
    std::shared_ptr<Node> x = root;
    while (x) {
        if (key < x->key) x = x->left;
        else if (x->key < key) x = x->right;
        else return x->val;
    }
    return Value();
}

template <typename Key, typename Value>
Key BST<Key, Value>::min() {
    std::shared_ptr<Node> x = root;
    while (x->left)
        x = x->left;
    return x->key;
}

template <typename Key, typename Value>
Key BST<Key, Value>::max() {
    std::shared_ptr<Node> x = root;
    while (x->right)
        x = x->right;
    return x->key;
}

template <typename Key, typename Value>
void BST<Key, Value>::put(Key key, Value val) {
    root = put(root, key, val);
}

template <typename Key, typename Value>
std::shared_ptr<typename BST<Key, Value>::Node>
BST<Key, Value>::put(std::shared_ptr<Node> x, Key key, Value val) {
    if (!x) return std::make_shared<Node>(key, val, 1);
    if (key < x->key) x->left = put(x->left, key, val);
    else if (x->key < key) x->right = put(x->right, key, val);
    else x->val = val;

    x->count = 1 + size(x->left) + size(x->right);
    return x;
}

template <typename Key, typename Value>
Key BST<Key, Value>::floor(Key key) {
    std::shared_ptr<Node> x = floor(root, key);
    if (!x) return Key();
    return x->key;
}

template <typename Key, typename Value>
std::shared_ptr<typename BST<Key, Value>::Node>
BST<Key, Value>::floor(std::shared_ptr<BST<Key, Value>::Node> x, Key key) {
    if (!x) return std::shared_ptr<Node>();

    if (key == x->key) return x;
    else if (key < x->key) return floor(x->left, key);

    std::shared_ptr<Node> t = floor(x->right, key);
    if (t) return t;
    else return x;
}

template <typename Key, typename Value>
int BST<Key, Value>::size(std::shared_ptr<Node> x) {
    if (!x) return 0;
    return x->count;
}

template <typename Key, typename Value>
int BST<Key, Value>::rank(std::shared_ptr<BST<Key, Value>::Node> x, Key key) {
    if (!x) return 0;
    if (key < x->key) return rank(x->left, key);
    else if (x->key < key) return 1 + size(x->left) + rank(x->right, key);
    else return size(x->left);
}

#endif //BINARYST_BINARYST_H
