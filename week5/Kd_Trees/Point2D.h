//
// Created by brayden on 2019-11-02.
//

#ifndef KD_TREES_POINT2D_H
#define KD_TREES_POINT2D_H

#include <string>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"


namespace kd_tree {
    class Point2D {
    public:
        Point2D() = default;
        Point2D(int x, int y) : x(x), y(y) { }
        Point2D(const Point2D &other) : x(other.x), y(other.y) { }
        int get_x() const { return x; }
        int get_y() const { return y; }
        double distancTo(const Point2D &that);
        int distanceSquaredTo(const Point2D &that);
        virtual void draw(cv::Mat &img) const ;
        std::string toString();
        virtual ~Point2D() = default;
    private:
        int x = 0, y = 0;
    };

    class inPoint2D : public Point2D {
    public:
        using Point2D::Point2D;
        void draw(cv::Mat &img) const;
    };

    bool operator==(const Point2D &lhs, const Point2D &rhs);

    bool operator<(const Point2D &lhs, const Point2D &rhs);

    class RectHV {
    public:
        RectHV() = default;
        RectHV(int xmin, int ymin, int xmax, int ymax) : xmin(xmin), ymin(ymin), xmax(xmax), ymax(ymax) {}
        int get_xmin() const { return xmin; }
        int get_ymin() const { return ymin; }
        int get_xmax() const { return xmax; }
        int get_ymax() const { return ymax; }
        bool constains(const Point2D &p) const ;
        bool intersects(const RectHV &that);
        double distanceTo(const Point2D &p);
        int distanceSquared(const Point2D &p);
        void draw(cv::Mat &img);
        std::string ToString();

    private:
        int xmin = 0, ymin = 0;
        int xmax = 0, ymax = 0;
    };

    bool operator==(const RectHV &lhs, const RectHV &rhs);
}


#endif //KD_TREES_POINT2D_H
