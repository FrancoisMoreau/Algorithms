//
// Created by brayden on 2019-09-08.
//

#ifndef COLLINEARPOINTS_LINESEGMENT_H
#define COLLINEARPOINTS_LINESEGMENT_H

#include "ColPoint.h"


class LineSegment {
public:
    LineSegment(ColPoint &a, ColPoint &b) : p(a), q(b) {}
    void draw(cv::Mat &img);
    std::string toString();

private:
    ColPoint p;
    ColPoint q;
};


#endif //COLLINEARPOINTS_LINESEGMENT_H
