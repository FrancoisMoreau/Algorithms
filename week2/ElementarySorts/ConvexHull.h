//
// Created by brayden on 2019-08-24.
//

#ifndef ELEMENTARYSORTS_CONVEXHULL_H
#define ELEMENTARYSORTS_CONVEXHULL_H

#include <vector>

struct Point2D {
    int x;
    int y;
    float angle = 0.f;
    Point2D() = default;
    Point2D(int x, int y) : x(x), y(y) {}
};

class ConvexHull {
public:
    ConvexHull() = default;
    ConvexHull(const std::initializer_list<Point2D> &il) : pvec(il) {}
    ConvexHull(const std::vector<Point2D> &vec) : pvec(vec) {}
    std::vector<Point2D> convex_run();

private:
    std::vector<Point2D> pvec;
    void find_base_point2D();
    void compute_angle();
    void sort_by_angle();
    static int ccw(const Point2D &a, const Point2D &b, const Point2D &c);
    Point2D base_point2D;
};


#endif //ELEMENTARYSORTS_CONVEXHULL_H
