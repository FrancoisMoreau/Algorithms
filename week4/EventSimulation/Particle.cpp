//
// Created by brayden on 2019-10-13.
//

#include "Particle.h"

const int Infinity = -1;
const int WallSize = 1000;

int input_cast(const double &num) {
    return static_cast<int>(num * 1000);
}

std::istream &read(std::istream &is, Particle &particle) {
    double rx, ry, vx, vy, radius, mass;
    is >> rx >> ry >> vx >> vy >> radius >> mass
    >> particle.r >> particle.g >> particle.b;
    particle.rx = input_cast(rx);
    particle.ry = input_cast(ry);
    particle.vx = input_cast(vx);
    particle.vy = input_cast(vy);
    particle.radius = input_cast(radius) ;
    particle.mass = static_cast<int>(mass);
    return is;
}

std::ostream &print(std::ostream &os, Particle &particle) {
    os << particle.rx << " " << particle.ry << " " << particle.vx << " "
    << particle.vy << " " << particle.radius << " \n";
    return os;
}

Particle &Particle::operator=(const Particle &rhs) {
    rx = rhs.rx;
    ry = rhs.ry;
    vx = rhs.vx;
    vy = rhs.vy;
    radius = rhs.radius;
    mass = rhs.mass;
    b = rhs.b, g = rhs.g, r = rhs.r;
    count = rhs.count;
}

void Particle::move(double dt) {
    rx += static_cast<int>(dt * vx);
    ry += static_cast<int>(dt * vy);
}

void Particle::draw(cv::Mat &img) {
    cv::Point center(rx, ry);
    cv::Scalar color(b, g, r);
    cv::circle(img, center, radius, color, -1, cv::LINE_AA);
}

double Particle::timeToHit(Particle &that) {
    if (this == &that) return Infinity;
    double dx = that.rx - rx, dy = that.ry - ry;
    double dvx = that.vx - vx, dvy = that.vy - vy;
    double dvdr = dx * dvx + dy * dvy;
    if (dvdr > 0) return Infinity;
    double dvdv = dvx * dvx + dvy * dvy;
    double drdr = dx * dx + dy * dy;
    double sigma = radius + that.radius;
    double d = dvdr * dvdr - dvdv * (drdr - sigma * sigma);
    if (d < 0) return Infinity;
    return -(dvdr + sqrt(d))/ dvdv;
}

double Particle::timeToHitHorizontalWall() {
    if (vy == 0) return Infinity;
    else if (vy < 0) return static_cast<double>(radius - ry) / vy;
    else return static_cast<double>(WallSize - radius - ry) / vy;
}

double Particle::timeToHitVerticalWall() {
    if (vx == 0) return Infinity;
    else if (vx < 0) return static_cast<double>(radius - rx) / vx;
    else return static_cast<double>(WallSize - radius - rx) / vx;
}

void Particle::bounceOff(Particle &that) {
    double dx = that.rx - rx, dy = that.ry - ry;
    double dvx = that.vx - vx, dvy = that.vy - vy;
    double dvdr = dx * dvx + dy * dvy;
    double dist = radius + that.radius;
    double J = 2 * mass * that.mass * dvdr / ((mass + that.mass) * dist);
    double Jx = J * dx / dist;
    double Jy = J * dy / dist;
    vx += Jx / mass;
    vy += Jy / mass;
    that.vx -= Jx / that.mass;
    that.vy -= Jy / that.mass;
    count++;
    that.count++;
}

void Particle::bounceOffHorizontalWall() {
    vy = -vy;
    count++;
}

void Particle::bounceOffVerticalWall() {
    vx = -vx;
    count++;
}
