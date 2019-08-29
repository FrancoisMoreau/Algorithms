//
// Created by brayden on 2019-08-28.
//

#include "IntersectionTwoSets.h"


bool comparePoints(const Point2D &lhs, const Point2D &rhs) {
    if (lhs.x < rhs.x) {
        return true;
    } else if (rhs.x < lhs.x) {
        return false;
    } else {
        if (lhs.y < rhs.y)
            return true;
        else
            return false;
    }
}


void IntersectionTwoSets::push_back(const Point2D &p) {
    pset.insert(p);
}