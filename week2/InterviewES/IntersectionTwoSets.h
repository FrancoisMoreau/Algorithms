//
// Created by brayden on 2019-08-28.
//

#ifndef INTERVIEWES_INTERSECTIONTWOSETS_H
#define INTERVIEWES_INTERSECTIONTWOSETS_H

#include <set>

struct Point2D {
    int x;
    int y;
    Point2D(int x, int y) : x(x), y(y) {}
};

bool comparePoints(const Point2D &lhs, const Point2D &rhs);

class IntersectionTwoSets {
public:
    IntersectionTwoSets() = default;
    void push_back(const Point2D &);
    size_t size() { return pset.size(); }

private:
    std::set<Point2D, decltype(comparePoints)*> pset{comparePoints};

};

//Attention here: the member initialization



#endif //INTERVIEWES_INTERSECTIONTWOSETS_H
