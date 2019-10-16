//
// Created by brayden on 2019-10-14.
//

#include "CollisionSystem.h"

Event &Event::operator=(const Event &rhs) {
    time = rhs.time;
    a = rhs.a;
    b = rhs.b;
    countA = rhs.countA;
    countB = rhs.countB;
    return *this;
}

bool Event::isValid() {
    if (a == nullptr && b == nullptr) return false;
    if (a != nullptr && a->get_count() != countA) return false;
    if (b != nullptr && b->get_count() != countB) return false;
    return true;
}

void CollisionSystem::predict(Particle *a) {
    if (a == nullptr) return;
    for (int i = 0; i < particles.size(); ++i) {
        double dt = a->timeToHit(particles[i]);
        if (dt > 0) pq.push(Event(t + dt, a, &particles[i]));
    }
    if (a->timeToHitHorizontalWall() > 0)
        pq.push(Event(t + a->timeToHitHorizontalWall(), nullptr, a));
    if (a->timeToHitVerticalWall() > 0)
        pq.push(Event(t + a->timeToHitVerticalWall(), a, nullptr));

}

void CollisionSystem::simulate() {
    for (auto &i : particles)
        predict(&i);
    pq.push(Event(0, nullptr, nullptr));

    cv::namedWindow("Simulation", cv::WINDOW_AUTOSIZE);

    while (!pq.empty()) {
        Event event = pq.top();
        pq.pop();

        if (!event.isValid()) continue;
        Particle *a = event.a;
        Particle *b = event.b;

        cv::Mat img(1000, 1000, CV_8UC3, cv::Scalar(255, 255, 255));

        for (auto &i : particles) {
            i.draw(img);
            i.move(event.time - t);
        }
        cv::imshow("Simulation", img);
        char c = (char) cv::waitKey(1);
        if (c == 27) break;

        t = event.time;
//        printf("t: %f\n", t);

        if (a != nullptr && b != nullptr) a->bounceOff(*b);
        else if (a != nullptr && b == nullptr) a->bounceOffVerticalWall();
        else if (a == nullptr && b != nullptr) b->bounceOffHorizontalWall();
        else if (a == nullptr && b == nullptr) redraw();


        predict(a);
        predict(b);
    }

}