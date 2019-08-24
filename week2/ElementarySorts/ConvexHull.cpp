#include "ConvexHull.h"
#include <cmath>

void ConvexHull::find_base_point2D() {
    base_point2D = pvec[0];
    for (auto &it : pvec) {
        if (it.y < base_point2D.y)
            base_point2D = it;
    }
}

void ConvexHull::compute_angle() {
    for (auto it = pvec.begin(); it != pvec.end(); ++it) {
        it->angle = atan2(it->y - base_point2D.y, it->x - base_point2D.x);
    }
}

void ConvexHull::sort_by_angle() {
    std::sort(pvec.begin(), pvec.end(), [](const Point2D &a, const Point2D &b) {
        return a.angle < b.angle;
    });
}

int ConvexHull::ccw(const Point2D &a, const Point2D &b, const Point2D &c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0) return 1;
    else if (area < 0) return -1;
    else return 0;
}



std::vector<Point2D> ConvexHull::convex_run(){
    find_base_point2D();
    compute_angle();
    sort_by_angle();
    std::vector<Point2D> result{pvec[0], pvec[1]};
    size_t i = 0, j = 2;
    size_t N = pvec.size();
    while (j != N) {
        if (ccw(result[i], result.back(), pvec[j]) > 0) {
            result.push_back(pvec[j]);
            ++i;
            ++j;
        } else {
            result.pop_back();
            --i;
        }
    }
    result.push_back(pvec[N - 1]);
    return result;
}