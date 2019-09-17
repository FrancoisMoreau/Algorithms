#include "DynamicMedian.h"
//
//void MaxPQ::swim(int key) {
//    while (key > 1) {
//        if (vec[key - 1] > vec[key / 2 - 1]) {
//            std::swap(vec[key - 1], vec[key / 2 - 1]);
//            key /= 2;
//        } else
//            break;
//    }
//}
//
//void MaxPQ::insert(int val) {
//    vec.push_back(val);
//    swim(size());
//}
//
//void MaxPQ::sink(int key) {
//    while (2 * key < vec.size()) {
//        int next = key * 2;
//        int max_key = (next < vec.size() && vec[next] > vec[next - 1]) ? next + 1 : next;
//        if (vec[max_key - 1] > vec[key - 1]) {
//            std::swap(vec[max_key - 1], vec[key - 1]);
//            key = max_key;
//        } else
//            break;
//    }
//}
//
//int MaxPQ::delMax() {
//    int ret_val = vec[0];
//    std::swap(vec[0], vec.back());
//    vec.pop_back();
//    sink(1);
//    return ret_val;
//}


void PriorityQueue::swim(int key) {
    while (key > 1) {
        if (cmp(vec[key - 1], vec[key / 2 - 1])) {
            std::swap(vec[key - 1], vec[key / 2 - 1]);
            key /= 2;
        } else
            break;
    }
}

void PriorityQueue::insert(int val) {
    vec.push_back(val);
    swim(size());
}

void PriorityQueue::sink(int key) {
    while (2 * key < vec.size()) {
        int next = key * 2;
        int max_key = (next < vec.size() && cmp(vec[next], vec[next - 1])) ? next + 1 : next;
        if (cmp(vec[max_key - 1], vec[key - 1])) {
            std::swap(vec[max_key - 1], vec[key - 1]);
            key = max_key;
        } else
            break;
    }
}

int PriorityQueue::delTop(){
    int ret_val = vec[0];
    std::swap(vec[0], vec.back());
    vec.pop_back();
    sink(1);
    return ret_val;
}

PriorityQueue &PriorityQueue::operator=(const PriorityQueue &rhs) {
    vec = rhs.vec;
    cmp = rhs.cmp;
    return *this;
}


int DynamicMedian::median() const {
    if (isEmpty())
        throw std::out_of_range("Empty Dynamic Structure");
    else
        return maxq.Top();
}

void DynamicMedian::insert(int val) {
    if (val <= median()) {
        if (maxq.size() != minq.size())
            minq.insert(maxq.delTop());
        maxq.insert(val);
    } else {
        minq.insert(val);
        if (maxq.size() < minq.size())
            maxq.insert(minq.delTop());
    }
}