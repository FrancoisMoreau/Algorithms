//
// Created by brayden on 2019-10-13.
//

#ifndef EVENTSIMULATION_PARTICLE_H
#define EVENTSIMULATION_PARTICLE_H

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

class Particle;

std::istream &read(std::istream &is, Particle &particle);
std::ostream &print(std::ostream &os, Particle &particle);

class Particle {
    friend std::istream &read(std::istream &is, Particle &particle);
    friend std::ostream &print(std::ostream &os, Particle &particle);
public:
    Particle() = default;
    Particle(int rx, int ry, int vx, int vy, int radius, int mass, int b, int g, int r) :
    rx(rx), ry(ry), vx(vx), vy(vy), radius(radius), mass(mass), b(b), g(g), r(r) { }
    Particle(const Particle &rhs) :
    rx(rhs.rx), ry(rhs.ry), vx(rhs.vx), vy(rhs.vy), radius(rhs.radius), mass(rhs.mass), b(rhs.b), g(rhs.g), r(rhs.r) {}
    Particle &operator=(const Particle &rhs);
    int get_count() { return count; }
    std::pair<int, int> get_coordinates() { return {rx, ry}; }

    void move(double dt);
    void draw(cv::Mat &img);
    double timeToHit(Particle &that);
    double timeToHitVerticalWall();
    double timeToHitHorizontalWall();
    void bounceOff(Particle &that);
    void bounceOffVerticalWall();
    void bounceOffHorizontalWall();
private:
    int rx = 0, ry = 0;
    double vx = 0, vy = 0;
    int radius = 100;
    int mass = 100;
    int r = 0, g = 0, b = 0;
    int count = 0;
};


#endif //EVENTSIMULATION_PARTICLE_H
