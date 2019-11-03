#include <iostream>
#include <random>
#include "Point2D.h"
#include "PointSET.h"
#include "fstream"

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
    std::ifstream input("../input100K.txt");
    if (!input)
        std::cerr << "NO FILE FOUND" << std::endl;

    kd_tree::PointSET pset;
    for (int i = 0; i < 1000; ++i) {
        double x, y;
        input >> x >> y;
        pset.insert(kd_tree::Point2D(static_cast<int>(1000 * x), static_cast<int>(1000 * y)));
    }


//    for (int i = 0; i < Points_Num; ++i) {
//        pset.insert(kd_tree::Point2D(get_random(0, 1000), get_random(0, 1000)));
//    }
    kd_tree::RectHV rec(300, 300, 800, 800);

    cv::Mat img(Height, Width, CV_8UC3, cv::Scalar(255, 255, 255));
    rec.draw(img);
    pset.draw(img);

    cv::namedWindow("PointSET", cv::WINDOW_AUTOSIZE);
    cv::imshow("PointSET", img);
    cv::waitKey(0);

    std::set<kd_tree::inPoint2D> in_pts = pset.range(rec);
    for (auto &i : in_pts)
        i.draw(img);

    cv::imshow("PointSET", img);
    cv::waitKey(0);

    //Kd-tree test
    img = cv::Scalar::all(255);
    cv::namedWindow("Kd_Tree", cv::WINDOW_AUTOSIZE);
    cv::imshow("Kd_Tree", img);
    cv::waitKey(0);


    return 0;
}