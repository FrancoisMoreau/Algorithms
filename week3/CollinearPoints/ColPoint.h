//
// Created by brayden on 2019-09-07.
//

#ifndef COLLINEARPOINTS_COLPOINT_H
#define COLLINEARPOINTS_COLPOINT_H

#include <string>
#include "opencv4/opencv2/imgproc.hpp"
#include "opencv4/opencv2/highgui.hpp"


class ColPoint {
public:
    ColPoint() = default;
    ColPoint(int x, int y) : x(x), y(y) {}
    void draw(cv::Mat &img);
    void drawTo(ColPoint &that, cv::Mat &img);
    std::string toString();
    ColPoint(const ColPoint &rhs) : x(rhs.x), y(rhs.y) {}
    ColPoint &operator=(const ColPoint &rhs);

    bool compareTo(ColPoint &);
    double slopeTo(ColPoint &);


private:
    int x;
    int y;
};


#endif //COLLINEARPOINTS_COLPOINT_H
