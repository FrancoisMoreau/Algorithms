//
// Created by brayden on 2019-09-30.
//

#include "SweepLine.h"
#include <random>
#include <queue>
#include <set>

void SLpoints::draw(cv::Mat &img) {
    cv::Point p(x, y);
    cv::circle(img, p, 2, cv::Scalar(0, 0, 0), -1);
}

void SLpoints::drawto(cv::Mat &img, SLpoints &that) {
    cv::Point pthis(x, y);
    cv::Point pthat(that.x, that.y);

    cv::line(img, pthis, pthat, cv::Scalar(0, 0, 0), 1);
//    cv::imshow("PointDraw", img);
//    cv::waitKey();
}

std::string SLpoints::toString() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

void InterPoint::draw(cv::Mat &img) {
    cv::Point p(x, y);
    cv::circle(img, p, 3, cv::Scalar(0, 0, 255), -1);
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

void generateSegments(std::vector<SLpoints> &endpoints, std::vector<SLsegments> &seg_vec) {
    for (int i = 0; i < 10; ++i) {
        //generate horizontal lines
        {
            int x1 = get_random_num(Width);
            int x2 = get_random_num(Width);
            int y = get_random_num(Height);
            SLpoints end0(x1, y);
            SLpoints end1(x2, y);
            endpoints.push_back(end0);
            endpoints.push_back(end1);
            seg_vec.emplace_back(end0, end1);
        }
        //generate vertical lines
        {
            int x = get_random_num(Width);
            int y1 = get_random_num(Height);
            int y2 = get_random_num(Height);
            SLpoints end0(x, y1);
            SLpoints end1(x, y2);
            endpoints.push_back(end0);
            endpoints.push_back(end1);
            seg_vec.emplace_back(SLpoints(x, y1), SLpoints(x, y2));
        }
    }
}

bool compareSLpts(const SLpoints &lhs, const SLpoints &rhs) {
    return lhs.x > rhs.x;
}


std::vector<InterPoint> sweepline(std::vector<SLpoints> &end_points) {
    std::priority_queue<SLpoints, std::vector<SLpoints>, decltype(compareSLpts)*> SLpts_pq(compareSLpts);
    for (auto &i : end_points)
        SLpts_pq.push(i);
    std::set<int> yset;

    std::vector<InterPoint> res;

    SLpoints prev_endpt = SLpts_pq.top();
    SLpts_pq.pop();
    yset.insert(prev_endpt.y);
    while (!SLpts_pq.empty()) {
        SLpoints cur_endpt = SLpts_pq.top();
//        printf("%s\n", (cur_endpt.toString()).c_str());
        SLpts_pq.pop();
        if (cur_endpt.x == prev_endpt.x) {
            yset.erase(prev_endpt.y);
            auto lo = yset.lower_bound(std::min(prev_endpt.y, cur_endpt.y));
            auto hi = yset.upper_bound(std::max(prev_endpt.y, cur_endpt.y));
            for (auto i = lo; i != hi; ++i) {
                res.emplace_back(cur_endpt.x, *i);
            }
        } else {
            if (yset.find(cur_endpt.y) != yset.end())
                yset.erase(cur_endpt.y);
            else
                yset.insert(cur_endpt.y);
        }
        prev_endpt = cur_endpt;
    }
    return res;
}