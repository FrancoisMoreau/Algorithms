//
// Created by brayden on 2019-08-28.
//

#include "IntersectionTwoSets.h"


bool comparePoints(const Point2D &lhs, const Point2D &rhs) {
//    int suml = lhs.x * lhs.x + lhs.y + lhs.y;
//    int sumr = rhs.x * rhs.x + rhs.y * rhs.y;
//    return (suml < sumr);
    return lhs.x < rhs.x;
}


void IntersectionTwoSets::push_back(const Point2D &p) {
    printf("s\n");
    pset.insert(p);
}