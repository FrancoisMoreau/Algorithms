//
// Created by brayden on 2019-09-26.
//

#ifndef BALANCEDBST_REDBLACKST_H
#define BALANCEDBST_REDBLACKST_H

#include <memory>
#include <queue>
#include <cassert>

template <typename Key, typename Val>
class RedBlackST {
public:
    void put(Key key, Val val) { root = put(root, key, val); root->color = BLACK; }
    Val get(Key key) { return get(root, key); };
    int height() { return height(root); };
private:
    struct Node {
        Key key;
        Val val;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        Node(Key key, Val val, bool color) : key(key), val(val), color(color) {}
        bool color;
    };
    static bool RED;
    static bool BLACK;
    bool isRed(std::shared_ptr<Node> x) { if (!x) return false; return x->color == RED; }
    std::shared_ptr<Node> rotateLeft(std::shared_ptr<Node> h) {
        assert(isRed(h->right));
        std::shared_ptr<Node> x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }
    std::shared_ptr<Node> rotateRight(std::shared_ptr<Node> h) {
        assert(isRed(h->left));
        std::shared_ptr<Node> x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }
    void flipColors(std::shared_ptr<Node> h) {
        assert(!isRed(h));
        assert(isRed(h->left));
        assert(isRed(h->right));

        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }

    std::shared_ptr<Node> put(std::shared_ptr<Node> x, Key key, Val val);
    Val get(std::shared_ptr<Node> x, Key key);
    int height(std::shared_ptr<Node> x);
    std::shared_ptr<Node> root;
};

template <typename Key, typename Val>
bool RedBlackST<Key, Val>::RED = true;


template <typename Key, typename Val>
bool RedBlackST<Key, Val>::BLACK = false;

template <typename Key, typename Val>
std::shared_ptr<typename RedBlackST<Key, Val>::Node>
RedBlackST<Key, Val>::put(std::shared_ptr<Node> x, Key key, Val val) {
    if (!x)
        return std::make_shared<Node>(key, val, RED);
//        return std::make_shared<Node>(key, val);
    if (key < x->key)
        x->left = put(x->left, key, val);
    else if (x->key < key)
        x->right = put(x->right, key, val);
    else
        x->val = val;

    if (isRed(x->right) && !isRed(x->left)) x = rotateLeft(x);
    if (isRed(x->left)  && isRed(x->left->left)) x = rotateRight(x);
    if (isRed(x->left) &&  isRed(x->right)) flipColors(x);

    return x;
}

template <typename Key, typename Val>
Val RedBlackST<Key, Val>::get(std::shared_ptr<RedBlackST<Key, Val>::Node> x, Key key) {
    if (!x)
        throw std::out_of_range("Key not found");
    if (key < x->key)
        return get(x->left, key);
    else if (x->key < key)
        return get(x->right, key);
    else
        return x->val;
}

template <typename Key, typename Val>
int RedBlackST<Key, Val>::height(std::shared_ptr<RedBlackST<Key, Val>::Node> x) {
    if (!x)
        return 1;
    return std::max(height(x->left), height(x->right)) + 1;
}

#endif //BALANCEDBST_REDBLACKST_H
