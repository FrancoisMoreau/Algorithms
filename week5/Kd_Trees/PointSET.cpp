//
// Created by brayden on 2019-11-02.
//

#include "PointSET.h"

namespace kd_tree {
    void PointSET::insert(const Point2D &p) {
        pset.insert(p);
    }

    bool PointSET::contains(const Point2D &p) {
        if (pset.find(p) != pset.end())
            return true;
        else
            return false;
    }

    void PointSET::draw(cv::Mat &img) {
        for (auto &i : pset)
            i.draw(img);
    }

    std::set<inPoint2D> PointSET::range(const kd_tree::RectHV &rect) {
        std::set<inPoint2D> inner_pts;
        for (auto &i : pset) {
            if (rect.constains(i))
                inner_pts.insert(inPoint2D(i.get_x(), i.get_y()));
        }
        return inner_pts;
    }

}