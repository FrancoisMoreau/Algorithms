//
// Created by brayden on 2019-10-14.
//

#include "CollisionSystem.h"

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
        pq.push(Event(t + dt, a, &particles[i]));
    }
    pq.push(Event(t + a->timeToHitVerticalWall(), a, nullptr));
    pq.push(Event(t + a->timeToHitHorizontalWall(), nullptr, a));
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
            i.move(event.time - t);
            i.draw(img);
        }
        cv::imshow("Simulation", img);
        char c = (char) cv::waitKey(100);
        if (c == 27) break;

        t = event.time;

        if (a != nullptr && b != nullptr) a->bounceOff(*b);
        else if (a != nullptr && b == nullptr) a->bounceOffVerticalWall();
        else if (a == nullptr && b != nullptr) b->bounceOffHorizontalWall();
        else if (a == nullptr && b == nullptr) redraw();


        predict(a);
        predict(b);
    }
}