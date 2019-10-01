//
// Created by brayden on 2019-09-30.
//

#ifndef GEOMETRICSEARCH_SWEEPLINE_H
#define GEOMETRICSEARCH_SWEEPLINE_H

#include <vector>
#include <string>

#include "opencv4/opencv2/imgproc.hpp"
#include "opencv4/opencv2/highgui.hpp"

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

void generateSegments(std::vector<SLpoints> &end_points, std::vector<SLsegments> &seg_vec);

std::vector<InterPoint> sweepline(std::vector<SLpoints> &end_points);

#endif //GEOMETRICSEARCH_SWEEPLINE_H
