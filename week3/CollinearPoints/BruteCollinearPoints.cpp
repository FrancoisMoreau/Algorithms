//
// Created by brayden on 2019-09-08.
//

#include "BruteCollinearPoints.h"

std::pair<ColPoint, ColPoint>
BruteCollinearPoints::compute_segments(std::vector<ColPoint> &pvec) {
    ColPoint psmall(pvec[0]), plarge(pvec[0]);
    int N = pvec.size();
    for (int i = 1; i < N; ++i) {
        if (!psmall.compareTo(pvec[i]))
            psmall = pvec[i];
        if (plarge.compareTo(pvec[i]))
            plarge = pvec[i];
    }
    return {psmall, plarge};
}

std::vector<LineSegment> BruteCollinearPoints::segments() {
    std::vector<LineSegment> linesegs;
    for (auto &i : CollinearPoints) {
        linesegs.emplace_back(i.first, i.second);
    }
    return linesegs;
}


BruteCollinearPoints::BruteCollinearPoints(std::vector<ColPoint> &points) {
    int N = points.size();
    ColPoint p0, p1, p2, p3;
    double slope1, slope2, slope3;
    int counts = 0;
    for (int i = 0; i < N - 3; ++i) {
        p0 = points[i];
        for (int j = i + 1; j < N; ++j) {
            p1 = points[j];
            slope1 = p0.slopeTo(p1);
            for (int l = j + 1; l < N; ++l) {
                p2 = points[l];
                slope2 = p0.slopeTo(p2);
                if (slope1 != slope2)
                    break;
                for (int m = l + 1; m < N; ++m) {
                    p3 = points[m];
                    slope3 = p0.slopeTo(p3);
                    if (abs(slope3 - slope1) > 1)
                        break;
                    else {
                        std::vector<ColPoint> pvec{p0, p1, p2, p3};
                        CollinearPoints.push_back(compute_segments(pvec));
                    }
                }
            }
        }
    }
}

