//
// Created by brayden on 2019-10-14.
//

#ifndef EVENTSIMULATION_COLLISIONSYSTEM_H
#define EVENTSIMULATION_COLLISIONSYSTEM_H

#include <queue>
#include <vector>
#include "Particle.h"

class CollisionSystem;

class Event {
    friend class CollisionSystem;
public:
//    Event() = default;
    Event(double t, Particle *a, Particle *b) : time(t), a(a), b(b) {
        if (a) countA = a->get_count();
        if (b) countB = b->get_count();
    }
//    Event(const Event &rhs) : time(rhs.time), a(rhs.a), b(rhs.b), countA(rhs.countA), countB(rhs.countB) {}
    bool operator<(const Event &rhs) const {
        return time < rhs.time;
    }
    bool isValid();

private:
    double time = 0.0;
    Particle *a, *b;
    int countA = 0, countB = 0;
};

inline bool Minpq_compareEvent(const Event &lhs, const Event &rhs) {
//    return rhs.operator<(lhs);
    return rhs < lhs;
}

class CollisionSystem {
public:
    CollisionSystem(const std::vector<Particle> &particles) : particles(particles) {}
    void simulate();
private:
    void predict(Particle *a);
    void redraw() { }

    std::priority_queue<Event, std::vector<Event>, decltype(Minpq_compareEvent)*> pq{Minpq_compareEvent};
    double t = 0.0;
    std::vector<Particle> particles;

};


#endif //EVENTSIMULATION_COLLISIONSYSTEM_H
