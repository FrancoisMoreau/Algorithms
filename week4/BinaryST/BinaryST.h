//
// Created by brayden on 2019-09-03.
//

#ifndef BINARYST_BINARYST_H
#define BINARYST_BINARYST_H

#include <memory>
#include <queue>


template <typename Key, typename Value>
class BST {
public:
    void put(Key key, Value val) { root = put(root, key, val); }
    Value get(Key key);
    Key min() { return min(root)->key; }
    Key max() { return max(root)->key; }
    void erase(Key key) { root = erase(root, key); }
    Key floor(Key key);
    Key ceiling(Key key);
    int size() { return size(root); }
    int rank(Key key) { return rank(root, key); }
    std::queue<Key> keys();
    Key select(int k) { return select(root, k)->key; }
    void delMin() { root = delMin(root); }

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
    std::shared_ptr<Node> ceiling(std::shared_ptr<Node> x, Key key);
    std::shared_ptr<Node> min(std::shared_ptr<Node> x) { return (x->left ? min(x->left) : x); }
    std::shared_ptr<Node> max(std::shared_ptr<Node> x) { return (x->right ? max(x->right) : x); }
    int size(std::shared_ptr<Node> x);
    int rank(std::shared_ptr<Node> x, Key key);
    void inorder(std::shared_ptr<Node> x, std::queue<Key> &q);
    std::shared_ptr<Node> select(std::shared_ptr<Node> x, int k);
    std::shared_ptr<Node> delMin(std::shared_ptr<Node> x);
    std::shared_ptr<Node> erase(std::shared_ptr<Node> x, Key key);

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
Key BST<Key, Value>::ceiling(Key key) {
    std::shared_ptr<Node> x = ceiling(root, key);
    if (!x)
        throw std::out_of_range("No ceiling for the key requested");
    return x->key;
}

template <typename Key, typename Value>
std::shared_ptr<typename BST<Key, Value>::Node>
BST<Key, Value>::ceiling(std::shared_ptr<BST<Key, Value>::Node> x, Key key) {
    if (!x) return std::shared_ptr<Node>();

    if (key == x->key) return x;
    else if (key > x->key) return ceiling(x->right, key);

    std::shared_ptr<Node> t = ceiling(x->left, key);
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

template <typename Key, typename Value>
std::queue<Key> BST<Key, Value>::keys() {
    std::queue<Key> q;
    inorder(root, q);
    return q;
}

template <typename Key, typename Value>
void BST<Key, Value>::inorder(std::shared_ptr<BST<Key, Value>::Node> x, std::queue<Key> &q) {
    if (!x) return;
    inorder(x->left, q);
    q.push(x->key);
    inorder(x->right, q);
}

template <typename Key, typename Value>
std::shared_ptr<typename BST<Key, Value>::Node>
BST<Key, Value>::select(std::shared_ptr<BST<Key, Value>::Node> x, int k) {
    if (!x)
        throw std::out_of_range("No key ranked as requested");
    int t = size(x->left);
    if (t < k) return select(x->right, k - t - 1);
    else if (t > k) return select(x->left, k);
    else return x;
}

template <typename Key, typename Value>
std::shared_ptr<typename BST<Key, Value>::Node>
BST<Key, Value>::delMin(std::shared_ptr<BST<Key, Value>::Node> x) {
    if (!(x->left)) return  x->right;
    x->left = delMin(x->left);
    x->count = 1 + size(x->left) + size(x->right);
    return x;
}

template <typename Key, typename Value>
std::shared_ptr<typename BST<Key, Value>::Node>
BST<Key, Value>::erase(std::shared_ptr<BST<Key, Value>::Node> x, Key key) {
    if (!x) throw std::out_of_range("cannot erase a key that does not exist");
    if (x->key < key) x->right = erase(x->right, key);
    else if (key < x->key) x->left = erase(x->left, key);
    else {
        if (!(x->right)) return x->left;
        if (!(x->left)) return x->right;

        std::shared_ptr<Node> t = x;
        x->val = min(t->right)->val;
        x->left = t->left;
        x->right = delMin(t->right);
    }
    x->count = size(x->left) + size(x->right) + 1;
    return x;
}


#endif //BINARYST_BINARYST_H
