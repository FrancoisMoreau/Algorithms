//
// Created by brayden on 2019-08-31.
//

#ifndef DEQUE_RANDOMQUE_RANDOMIZEDQUEUE_H
#define DEQUE_RANDOMQUE_RANDOMIZEDQUEUE_H

#include <random>
#include <memory>
#include <string>

int get_random(int t) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, t);
    int dice_roll = distribution(rng);
    return dice_roll;
}

template <typename T>
class RandomizedQueue {
public:
    RandomizedQueue() : first(nullptr), first_val(nullptr), last_val(nullptr), cap(nullptr) { }
    bool isEmpty() const { return capacity() == 0; }
    int size() const { return last_val - first_val + 1; }
    int capacity() const { return cap - first; } 
    void enque(const T &);
    T dequeue();
    ~ RandomizedQueue();
private:
    static std::allocator<T> alloc;
    void chk_n_alloc() { if (last_val == cap) reallocate(); }
    void alloc_n_move(size_t new_cap);
    void free();
    void reallocate();
    T *first;
    T *first_val;
    T *last_val;
    T *cap;
};

template <typename T>
std::allocator<T> RandomizedQueue<T>::alloc;

template <typename T>
void RandomizedQueue<T>::free() {
    if (first) {
        for (auto p = last_val; p >= first; )
            alloc.destroy(p--);
        alloc.deallocate(first, cap - first);
    }
}

template <typename T>
RandomizedQueue<T>::~RandomizedQueue() {
    free();
}

template <typename T>
void RandomizedQueue<T>::alloc_n_move(size_t new_cap) {
    auto new_data = alloc.allocate(new_cap);
    auto dest = new_data;
    auto first_val_inc = first_val;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*first_val_inc++));
    free();
    first = first_val = new_data;
    last_val = --first_val_inc;
    cap = first + new_cap;
}

template <typename T>
void RandomizedQueue<T>::reallocate() {
    int new_cap = size() ? 2 * size() : 1;
    alloc_n_move(new_cap);
}

template <typename T>
void RandomizedQueue<T>::enque(const T &val) {
    chk_n_alloc();
    alloc.constrct(last_val++, val);
}

template <typename T>
T RandomizedQueue<T>::dequeue() {
    int range = size() - 1;
    int del_idx = get_random(range);
    int pop_val = *(first_val + del_idx);
    *(first_val + del_idx) = *(last_val);
    alloc.destroy(last_val--);
    return del_idx;
}


#endif //DEQUE_RANDOMQUE_RANDOMIZEDQUEUE_H
