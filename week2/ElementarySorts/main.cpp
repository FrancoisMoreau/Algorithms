#include <iostream>
#include <random>
#include <chrono>
#include <ctime>

#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "ConvexHull.h"

#include <opencv4/opencv2/opencv.hpp>
using namespace cv;

#define ARR_LEN 10000
#define IMG_SIZE 800

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

int get_random(int n) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n);
    int dice_roll = distribution(rng);
    return dice_roll;
}

void Knuth_Shuffle(std::vector<int> &vec) {
    int N = vec.size();
    for (int i = 0; i != N; ++i) {
        std::swap(vec[i], vec[get_random(i)]);
    }
}

using std::cout;

int main() {


    std::default_random_engine e;
    std::uniform_int_distribution<int> u(0, ARR_LEN);

    std::vector<int> StdSortVec, SelSortVec, InserSortVec, ShellSortVec;
    for (size_t i = 0; i < ARR_LEN; ++i) {
        StdSortVec.push_back(u(e));
    }
    SelSortVec = StdSortVec;
    InserSortVec = StdSortVec;
    ShellSortVec = StdSortVec;

    TimeVar t1 = timeNow();
    std::sort(StdSortVec.begin(), StdSortVec.end());
    TimeVar t2 = timeNow();

    std::cout << "STL sort: " << duration(t2 - t1) << " ms\n";

    t1 = timeNow();
    SelectionSort(SelSortVec);
    t2 = timeNow();
    std::cout << "Selection sort: " << duration(t2 - t1) << " ms\n";

    t1 = timeNow();
    InsertionSort(InserSortVec);
    t2 = timeNow();
    std::cout << "Insertion sort: " << duration(t2 - t1) << " ms\n";

    t1 = timeNow();
    ShellSort(ShellSortVec);
    t2 = timeNow();
    std::cout << "Shell sort: " << duration(t2 - t1) << " ms\n";

    for (size_t i = 0; i < ARR_LEN; ++i) {
        if (SelSortVec[i] != StdSortVec[i])
            std::cout << " not same !\n";
        if (InserSortVec[i] != StdSortVec[i])
            std::cout << " not same !\n";
        if (ShellSortVec[i] != StdSortVec[i])
            std::cout << " not same !\n";
    }

    std::vector<int> to_shuffle{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int first_is_one = 0;
    for (int i = 0; i < ARR_LEN; ++i) {
        Knuth_Shuffle(to_shuffle);
        if (to_shuffle[0] == 1)
            first_is_one += 1;
    }
    printf("probablity: %f\n", first_is_one * 1.f / ARR_LEN);



    cv::Mat image = cv::imread("../white.jpg");
    int size_x = image.rows;
    int size_y = image.cols;
    cout << "input image size: " << size_x << " x " << size_y << std::endl;
    cv::resize(image, image, cv::Size(IMG_SIZE, IMG_SIZE), 0, 0, cv::INTER_LINEAR);

//    cout << "--------------Convec Hull---------------\n";
    std::vector<Point2D> PtVec;
    PtVec.reserve(20);
    std::vector<cv::Point> cvpoints;
    for (int i = 0; i < 20; ++i) {
        int x = get_random(IMG_SIZE -1 );
        int y = get_random(IMG_SIZE -1 );
        PtVec.emplace_back(x, y);
        cvpoints.emplace_back(Point(x, y));
    }
    // pic out every raw points
    for (auto &p2 : cvpoints) {
        circle(image, p2, 3,Scalar(255,0,0),-1);
    }

    ConvexHull convhull(PtVec);
    std::vector<Point2D> res = convhull.convex_run();

    // pic out every vertices
    for (auto &i : res) {
        circle(image, Point(i.x, i.y), 10, Scalar(0, 255, 0), -1);
    }

    //add the first point to connect first-last
    res.push_back(res[0]);
    size_t N = res.size();

    for (int i = 0; i != N - 1; ++i) {
        cv::Point p1(res[i].x, res[i].y);
        cv::Point p2(res[i + 1].x, res[i + 1].y);
        line(image, p1, p2, Scalar(33, 33, 133), 2);
    }

    namedWindow("origin");
    imshow("origin", image);
    waitKey(0);

    return 0;
}
