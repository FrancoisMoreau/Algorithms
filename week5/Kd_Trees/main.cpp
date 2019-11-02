#include <iostream>
#include <random>
#include "Point2D.h"
#include "PointSET.h"

const int Height = 1000;
const int Width = 1000;
const int Points_Num = 100;

int get_random(int lo, int hi) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(lo, hi);
    int dice_roll = distribution(rng);
    return dice_roll;
}

int main() {
    kd_tree::PointSET pset;
    for (int i = 0; i < Points_Num; ++i) {
        pset.insert(kd_tree::Point2D(get_random(0, 1000), get_random(0, 1000)));
    }
    kd_tree::RectHV rec(300, 300, 800, 800);

    cv::Mat img(Height, Width, CV_8UC3, cv::Scalar(255, 255, 255));
    rec.draw(img);
    pset.draw(img);

    cv::namedWindow("Kd_Trees", cv::WINDOW_AUTOSIZE);
    cv::imshow("Kd_Trees", img);
    cv::waitKey(0);

    std::set<kd_tree::inPoint2D> in_pts = pset.range(rec);
    for (auto &i : in_pts)
        i.draw(img);


    cv::imshow("Kd_Trees", img);
    cv::waitKey(0);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}