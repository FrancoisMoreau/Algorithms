//
// Created by brayden on 2019-08-31.
//

#ifndef DEQUE_RANDOMQUE_SIMPLERANDOMIZEDQUE_H
#define DEQUE_RANDOMQUE_SIMPLERANDOMIZEDQUE_H

#include <vector>

extern int get_random(int t);

template <typename T>
class SimpleRandomizedQueue {
public:
    SimpleRandomizedQueue() = default;
    bool isEmpty() const { return vec.empty(); }
    int size() const { return vec.size(); }
    void enque(const T&);
    T dequeue();
private:
    std::vector<T> vec;

};

template <typename T>
void SimpleRandomizedQueue<T>::enque(const T &val) {
    vec.push_back(val);
}

template <typename T>
T SimpleRandomizedQueue<T>::dequeue() {
    int idx = get_random(vec.size() - 1);
    std::swap(vec[idx], vec[vec.size() - 1]);
    int val = vec.back();
    vec.pop_back();
    return val;
}

#endif //DEQUE_RANDOMQUE_SIMPLERANDOMIZEDQUE_H
