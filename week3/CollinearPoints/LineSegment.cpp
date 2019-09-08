//
// Created by brayden on 2019-09-08.
//

#include "LineSegment.h"

void LineSegment::draw(cv::Mat &img) {
    p.drawTo(q, img);
}

std::string LineSegment::toString() {
    return p.toString() + " => " + q.toString();
}