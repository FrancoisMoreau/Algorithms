//
// Created by brayden on 2019-11-02.
//

#include "Point2D.h"

namespace kd_tree {
    int Point2D::distanceSquaredTo(const kd_tree::Point2D &that) {
        int dx = that.x - x;
        int dy = that.y -y;
        return dx * dx + dy * dy;
    }

    double Point2D::distancTo(const kd_tree::Point2D &that){
        return sqrt(distanceSquaredTo(that));
    }

    void Point2D::draw(cv::Mat &img) const {
        cv::Point p(x, y);
        cv::circle(img, p, 5, cv::Scalar(0, 0, 0), -1, cv::LINE_AA);
    }

    void inPoint2D::draw(cv::Mat &img) const {
        cv::Point p(get_x(), get_y());
        cv::circle(img, p, 5, cv::Scalar(0, 0, 255), -1, cv::LINE_AA);
    }

    std::string Point2D::toString() {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    bool operator==(const Point2D &lhs, const Point2D &rhs) {
        return (lhs.get_x() == rhs.get_x()) && (lhs.get_y() == rhs.get_y());
    }

    bool operator<(const Point2D &lhs, const Point2D &rhs) {
        if (lhs.get_x() < rhs.get_x())
            return true;
        else if (lhs.get_x() > rhs.get_x())
            return false;
        else {
            if (lhs.get_y() < rhs.get_y())
                return true;
            else
                return false;
        }
    }

    bool operator<(const inPoint2D &lhs, const inPoint2D &rhs) {
        return *(&lhs) < *(&rhs);
//        return Point2D(lhs.get_x(), lhs.get_y()) < Point2D(rhs.get_x(), rhs.get_y());
    }

    bool RectHV::constains(const kd_tree::Point2D &p) const {
        return (p.get_x() >= xmin && p.get_x() <= xmax
        && p.get_y() >= ymin && p.get_y() <= ymax);
    }

    int RectHV::distanceSquared(const kd_tree::Point2D &p) {
        int dx = 0, dy = 0;
        if (p.get_x() < xmin) dx = p.get_x() - xmin;
        else if (p.get_x() > xmax) dx = p.get_x() - xmax;
        if (p.get_y() < ymin) dy = p.get_y() - ymin;
        else if (p.get_y() > ymax) dy = p.get_y() - ymax;
        return dx * dx + dy * dy;
    }

    double RectHV::distanceTo(const kd_tree::Point2D &p) {
        return distanceSquared(p);
    }

    bool RectHV::intersects(const kd_tree::RectHV &that) {
        return (xmax >= that.xmin && xmin <= that.xmax
        && ymax >= that.ymin && ymin <= that.ymax);
    }

    void RectHV::draw(cv::Mat &img) {
        cv::rectangle(img, cv::Point(xmin, ymin), cv::Point(xmax, ymax), cv::Scalar(0, 0, 255), 5);
    }

    std::string RectHV::ToString() {
        return "[" + std::to_string(xmin) + ", " + std::to_string(xmax)
        + "] x [" + std::to_string(ymin) + ", " + std::to_string(ymax) + "]";
    }
}
