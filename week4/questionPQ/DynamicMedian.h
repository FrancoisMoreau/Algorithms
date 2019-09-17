//
// Created by brayden on 2019-09-17.
//

#ifndef QUESTIONPQ_DYNAMICMEDIAN_H
#define QUESTIONPQ_DYNAMICMEDIAN_H

#include <vector>
#include <functional>

//class MaxPQ {
//public:
//    MaxPQ() = default;
//    void insert(int val);
//    int delMax();
//    bool isEmpty() const { return vec.size() == 0; }
//    size_t size() const { return vec.size(); }
//private:
//    std::vector<int> vec;
//    void swim(int key);
//    void sink(int key);
//};

class PriorityQueue {
public:
    PriorityQueue() = default;
    PriorityQueue(std::function<bool (int, int)> cmp) : cmp(cmp) {}
    PriorityQueue(const PriorityQueue &rhs) : vec(rhs.vec), cmp(rhs.cmp) {}
    PriorityQueue &operator=(const PriorityQueue &rhs);
    void insert(int val);
    int Top() const {
        if (!isEmpty()) return vec[0];
        else throw std::out_of_range("top on an empty PQ");
    }
    int delTop();
    bool isEmpty() const { return vec.size() == 0; }
    size_t size() const { return vec.size(); }

private:
    std::vector<int> vec;
    void swim(int key);
    void sink(int key);
//    static bool compare(const int &key0, const int &key1);
    std::function<bool (int, int)> cmp = std::greater<int>();
};


class DynamicMedian {
public:
    void insert(int val);
    int median() const;
    int delMid();
    size_t size() const { return maxq.size() + minq.size(); }
    bool isEmpty() const { return  size() == 0; }

private:
    PriorityQueue maxq, minq = PriorityQueue([](int a, int b) { return a < b; });

};


#endif //QUESTIONPQ_DYNAMICMEDIAN_H
