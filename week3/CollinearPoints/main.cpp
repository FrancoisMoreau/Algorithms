#include <iostream>
#include <random>
#include <fstream>

#include "ColPoint.h"
#include "LineSegment.h"
#include "BruteCollinearPoints.h"

using std::cout;
using std::endl;

const int Arr_Len = 10000;
const int Img_Size = 4000;

int get_random(int n) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n);
    int dice_roll = distribution(rng);
    return dice_roll;
}

int main( int argc, char** argv )
{
    std::ifstream input("../input80.txt");
    if (!input)
        throw std::runtime_error("NO input file");
    int pt_size, x, y, img_size = 0;
    std::vector<ColPoint> colpoints;
    input >> pt_size;
    while (input) {
        input >> x;
        input >> y;
        x = x/10;
        y = y/10;
        colpoints.emplace_back(x, y);
    }

    cv::Mat img(Img_Size, Img_Size, CV_8UC3, cv::Scalar(255, 255, 255));

    for (auto &i : colpoints)
        i.draw(img);

    BruteCollinearPoints brutePts(colpoints);

    std::vector<LineSegment> lines = brutePts.segments();
    cout << " size: " << lines.size() << endl;

    for (auto &i : lines)
        i.draw(img);

    cv::resize(img, img, cv::Size(800, 800), 0, 0, cv::INTER_AREA);

    cv::namedWindow("MyWindow", cv::WINDOW_AUTOSIZE);
    cv::imshow("Points", img);

    cv::waitKey();

    return 0;
}
