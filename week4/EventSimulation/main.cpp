#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Particle.h"
#include "CollisionSystem.h"

using std::cout;
using std::endl;

using std::vector;

const int Img_Size = 1000;

int main() {
//    std::ifstream infile("../p10.txt");
//    std::ifstream infile("../p100-.125K.txt");
//    std::ifstream infile("../p100-2K.txt");
    std::ifstream infile("../billiards5.txt");
    if (!infile)
        std::cerr << "NO FILE FOUND\n";
    int pt_count;
    infile >> pt_count;
    vector<Particle> particles;
    particles.reserve(pt_count);

    Particle temp;
    for (int i = 0; i < pt_count; ++i) {
        read(infile, temp);
        particles.push_back(temp);
//        if (i == 0) print(cout, temp);
    }
    cout << particles.size() << endl;
    for (auto &i : particles)
        print(cout, i);

//    for (int i = 0; i < 5; ++i)
//        particles.pop_back();

//    cv::Mat img(Img_Size, Img_Size, CV_8UC3, cv::Scalar(255, 255, 255));

//    for (auto &i : particles)
//        i.draw(img);

    //our simulation
    CollisionSystem collision(particles);
    collision.simulate();

//    cv::namedWindow("Particle", cv::WINDOW_AUTOSIZE);
//    cv::imshow("Particle", img);
//    cv::waitKey(0);

    return 0;
}