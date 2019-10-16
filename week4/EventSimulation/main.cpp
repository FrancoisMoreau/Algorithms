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
//    std::ifstream infile("../p100-2K.txt");
    std::ifstream infile("../p1000-2K.txt");
//    std::ifstream infile("../brownian2.txt");
//    std::ifstream infile("../billiards5.txt");
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
    }
    cout << particles.size() << endl;
//    for (auto &i : particles)
//        print(cout, i);

    //our simulation
    CollisionSystem collision(particles);
    collision.simulate();

    return 0;
}