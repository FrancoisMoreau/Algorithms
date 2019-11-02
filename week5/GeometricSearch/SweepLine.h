//
// Created by brayden on 2019-09-30.
//

#ifndef GEOMETRICSEARCH_SWEEPLINE_H
#define GEOMETRICSEARCH_SWEEPLINE_H

#include <vector>
#include <string>

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

const int Width = 800;
const int Height = 600;

class SLpoints {
public:
    SLpoints() = default;
    SLpoints(int x, int y) : x(x), y(y) {}
    SLpoints(const SLpoints &p) : x(p.x), y(p.y) {}
    virtual void draw(cv::Mat &img);
    void drawto(cv::Mat &img, SLpoints &that);
    std::string toString();
    int get_x() const {return x; }
    int get_y() const {return y;}

protected:
    int x, y;
};

class InterPoint : public SLpoints {
public:
    using SLpoints::SLpoints;
    void draw(cv::Mat &img) override;
};

class SLsegments {
public:
    SLsegments() = default;
    SLsegments(SLpoints p, SLpoints q) : p(p), q(q) {}
    void draw(cv::Mat &img);
    std::string toString();
private:
    SLpoints p, q;
};

void generateSegments(std::vector<SLpoints> &horizontal_pts,
                      std::vector<SLpoints> &vertical_pts, std::vector<SLsegments> &seg_vec);

template <typename T>
void draw_pic(std::vector<T> &pic_parts, cv::Mat &img) {
    for (auto &i : pic_parts)
        i.draw(img);
}

std::vector<InterPoint> sweepline(std::vector<SLpoints> &h_pts, std::vector<SLpoints> &v_pts);

#endif //GEOMETRICSEARCH_SWEEPLINE_H
