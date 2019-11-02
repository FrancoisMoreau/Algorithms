//
// Created by brayden on 2019-09-30.
//

#include "SweepLine.h"
#include <random>
#include <queue>
#include <set>
#include <cstdio>

void SLpoints::draw(cv::Mat &img) {
    cv::Point p(x, y);
    cv::circle(img, p, 3, cv::Scalar(0, 0, 0), -1, cv::LINE_AA);
}

void SLpoints::drawto(cv::Mat &img, SLpoints &that) {
    cv::Point pthis(x, y);
    cv::Point pthat(that.x, that.y);

    cv::line(img, pthis, pthat, cv::Scalar(0, 0, 0), 1);
}

std::string SLpoints::toString() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

void InterPoint::draw(cv::Mat &img) {
    cv::Point p(x, y);
    cv::circle(img, p, 3, cv::Scalar(0, 0, 255), -1, cv::LINE_AA);
}


void SLsegments::draw(cv::Mat &img) {
    p.drawto(img, q);
}

std::string SLsegments::toString() {
    return p.toString() + " => " + q.toString();
}

int get_random_num(int hi) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, hi);
    int dice_roll = distribution(rng);
    return dice_roll;
}

void generate_horizontal(std::vector<SLpoints> &horizontal_pts, std::vector<SLsegments> &seg) {
    int x1 = get_random_num(Width);
    int x2 = get_random_num(Width);
    int y = get_random_num(Height);
    SLpoints end0(x1, y);
    SLpoints end1(x2, y);
    horizontal_pts.push_back(end0);
    horizontal_pts.push_back(end1);
    seg.emplace_back(end0, end1);
}


void generate_vertical(std::vector<SLpoints> &vertical_pts, std::vector<SLsegments> &seg) {
    int x = get_random_num(Width);
    int y1 = get_random_num(Height);
    int y2 = get_random_num(Height);
    SLpoints end0(x, y1);
    SLpoints end1(x, y2);
    vertical_pts.push_back(end0);
    vertical_pts.push_back(end1);
    seg.emplace_back(SLpoints(x, y1), SLpoints(x, y2));
}

void generateSegments(std::vector<SLpoints> &horizontal_pts,
        std::vector<SLpoints> &vertical_pts, std::vector<SLsegments> &seg_vec) {
    for (int i = 0; i < 10; ++i) {
        generate_horizontal(horizontal_pts, seg_vec);
        generate_vertical(vertical_pts, seg_vec);
    }
}

bool compareSLpts(const SLpoints &lhs, const SLpoints &rhs) {
    return lhs.get_x() > rhs.get_x();
}

std::vector<InterPoint> sweepline(std::vector<SLpoints> &horizontal_pts, std::vector<SLpoints> &vertical_pts) {
    std::priority_queue<SLpoints, std::vector<SLpoints>, decltype(compareSLpts)*> horizontal_pq(compareSLpts);
    std::priority_queue<SLpoints, std::vector<SLpoints>, decltype(compareSLpts)*> vertical_pq(compareSLpts);

    for (auto &i : horizontal_pts) horizontal_pq.push(i);
    for (auto &i : vertical_pts) vertical_pq.push(i);

    std::set<int> h_pts_y;
    std::vector<InterPoint> intersection;

    while (!horizontal_pq.empty() && !vertical_pq.empty()) {
        SLpoints h_top = horizontal_pq.top();
        SLpoints v_top = vertical_pq.top();

        if (h_top.get_x() < v_top.get_x()) {
            if (h_pts_y.find(h_top.get_y()) == h_pts_y.end())
                h_pts_y.insert(h_top.get_y());
            else
                h_pts_y.erase(h_top.get_y());
            horizontal_pq.pop();
        } else {
            vertical_pq.pop();
            auto v_top2 = vertical_pq.top();
            vertical_pq.pop();
            auto lo = h_pts_y.lower_bound(std::min(v_top.get_y(), v_top2.get_y()));
            auto hi = h_pts_y.upper_bound(std::max(v_top.get_y(), v_top2.get_y()));
            for (auto i = lo; i != hi; ++i) {
                intersection.emplace_back(v_top.get_x(), *i);
            }
        }
    }

    return intersection;
}
