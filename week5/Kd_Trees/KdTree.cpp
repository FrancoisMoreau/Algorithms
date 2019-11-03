//
// Created by brayden on 2019-11-03.
//

#include "KdTree.h"

namespace kd_tree {
    std::shared_ptr<Node> KdTree::put(std::shared_ptr<kd_tree::Node> x, const kd_tree::Point2D &pt, int level) {
        if (!x)
            return std::make_shared<Node>(pt);
        if (level & 0x1) {
            return put_odd(x, pt, level);
        } else {
            return put_even(x, pt, level);
        }
    }

    std::shared_ptr<Node> KdTree::put_even(std::shared_ptr<kd_tree::Node> x, const kd_tree::Point2D &pt, int level) {
        if (pt.get_x() < x->val.get_x())
            x->left = put(x->left, pt, level + 1);
        else if (pt.get_x() > x->val.get_x())
            x->right = put(x->right, pt, level + 1);

        return x;
    }


    std::shared_ptr<Node> KdTree::put_odd(std::shared_ptr<kd_tree::Node> x, const kd_tree::Point2D &pt, int level){
        if (pt.get_y() < x->val.get_y())
            x->left = put(x->left, pt, level + 1);
        else if (pt.get_y() > x->val.get_y())
            x->right = put(x->right, pt, level + 1);

        return x;
    }
}
