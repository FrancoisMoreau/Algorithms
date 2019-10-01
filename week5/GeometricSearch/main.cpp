#include <iostream>
#include <random>
#include <map>
#include <string>

#include "RangeSearch.h"
#include "SweepLine.h"

typedef unsigned Score;

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    std::map<Score, std::string> grades;
    for (int i = 0; i < 10; ++i) {
        grades.insert({get_random(60, 100), gen_rand_name()});
    }
    auto lo = grades.lower_bound(80);
    auto hi = grades.upper_bound(90);
    cout << "Grades between 80 and 90: \n";
    for (auto i = lo; i != hi; ++i) {
        cout << i->second  << " : " << i->first << endl;
    }

    cout << "\n\n\nSweep Line Algorithm: \n";
    cv::Mat img(Height, Width, CV_8UC3, cv::Scalar(255, 255, 255));
    vector<SLsegments> linesegs;
    vector<SLpoints> endpoints;
    generateSegments(endpoints, linesegs);
    for (auto &i : endpoints)
        i.draw(img);
    for (auto &i : linesegs) {
        i.draw(img);
//        cout << i.toString()  << endl;
    }

    std::vector<InterPoint> intersectionPts =  sweepline(endpoints);
    for (auto &i : intersectionPts)
        i.draw(img);

    cv::namedWindow("MyWindow", cv::WINDOW_AUTOSIZE);
    cv::imshow("Segments", img);

    cv::waitKey();

    return 0;
}