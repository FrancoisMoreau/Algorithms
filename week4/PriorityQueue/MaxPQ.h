//
// Created by brayden on 2019-08-31.
//

#ifndef PRIORITYQUEUE_MAXPQ_H
#define PRIORITYQUEUE_MAXPQ_H

#include <vector>

class MaxPQ {
public:
    MaxPQ() : keys(1), N(0) {}
    bool isEmpty() const { return N == 0; }
    int delMax();
    void insert(int val);

private:
    void swim(int k);
    void sink(int k);
    std::vector<int> keys;
    int N;
};


#endif //PRIORITYQUEUE_MAXPQ_H
