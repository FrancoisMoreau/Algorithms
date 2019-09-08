#include "ColPoint.h"

ColPoint &ColPoint::operator=(const ColPoint &rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
}

void ColPoint::draw(cv::Mat &img) {
    cv::Point p(x, y);

    cv::circle(img, p, 10, cv::Scalar(0, 255, 0), -1);

//    cv::imshow("Point", img);
//    char key = (char)cv::waitKey();
}

void ColPoint::drawTo(ColPoint &that, cv::Mat &img) {
    cv::Point pthis(x, y);
    cv::Point pthat(that.x, that.y);

    cv::line(img, pthis, pthat, cv::Scalar(33, 33, 133), 10);
//    cv::imshow("PointDraw", img);
//    cv::waitKey();
}

std::string ColPoint::toString() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

bool ColPoint::compareTo(ColPoint &that) {
    if (y < that.y || (y == that.y && x < that.x))
        return true;
    return false;
}

double ColPoint::slopeTo(ColPoint &that) {
    return (that.y - y) * 1.f / (that.x - x);
}