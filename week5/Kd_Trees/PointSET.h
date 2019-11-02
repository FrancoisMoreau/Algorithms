//
// Created by brayden on 2019-11-02.
//

#ifndef KD_TREES_POINTSET_H
#define KD_TREES_POINTSET_H

#include <set>
#include "Point2D.h"

namespace kd_tree {
    class PointSET {
    public:
        PointSET() = default;
        bool isEmpty() const { return pset.empty(); }
        int size() const { return pset.size(); }
        void insert(const Point2D &p);
        bool contains(const Point2D &p);
        void draw(cv::Mat &img);
        std::set<Point2D>::iterator begin() { return pset.begin(); }
        std::set<Point2D>::iterator end() {return pset.end();}
        std::set<inPoint2D> range(const RectHV &rect);
        Point2D nearest(const Point2D &p);

    private:
        std::set<Point2D> pset;
    };
}

#endif //KD_TREES_POINTSET_H
