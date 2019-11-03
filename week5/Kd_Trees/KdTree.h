//
// Created by brayden on 2019-11-03.
//

#ifndef KD_TREES_KDTREE_H
#define KD_TREES_KDTREE_H

#include <memory>
#include "Point2D.h"

namespace kd_tree {
    struct Node {
        Node() = default;
        Node(const Point2D &pt) : val(pt) {}
        Node(int x, int y) : val(Point2D(x, y)) {}
        Point2D val;
        std::shared_ptr<Node> left, right;
    };

    class KdTree {
    public:
        KdTree() = default;
        void put(const Point2D &pt) { root = put(root, pt, 0); };
    private:
        std::shared_ptr<Node> put(std::shared_ptr<Node> x, const Point2D &pt, int level);
        std::shared_ptr<Node> put_even(std::shared_ptr<Node> x, const Point2D &pt, int level);
        std::shared_ptr<Node> put_odd(std::shared_ptr<Node> x, const Point2D &pt, int level);
        std::shared_ptr<Node> root;
    };
}


#endif //KD_TREES_KDTREE_H
