//
// Created by brayden on 2019-09-08.
//

#ifndef COLLINEARPOINTS_BRUTECOLLINEARPOINTS_H
#define COLLINEARPOINTS_BRUTECOLLINEARPOINTS_H

#include <vector>
#include "ColPoint.h"
#include "LineSegment.h"

class BruteCollinearPoints {
public:
    BruteCollinearPoints(std::vector<ColPoint> &points);
    int numberOfSegments() { return CollinearPoints.size(); };
    std::vector<LineSegment> segments();

private:
    std::vector<std::pair<ColPoint, ColPoint>> CollinearPoints;
    std::pair<ColPoint, ColPoint> compute_segments(std::vector<ColPoint> &pvec);
};


#endif //COLLINEARPOINTS_BRUTECOLLINEARPOINTS_H
