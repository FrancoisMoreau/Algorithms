//
// Created by brayden on 19-8-22.
//

#ifndef WEEK2_STACKWITHMAX_H
#define WEEK2_STACKWITHMAX_H

#include <iostream>
#include <vector>

template <typename T>
class StackWithMax {
public:
    StackWithMax() = default;
    bool isEmpty() const { return vec.empty(); }
    void push(const T &);
    T pop();
    T max() const { return stk_max.back(); }
private:
    std::vector<T> vec;
    std::vector<T> stk_max;
};

template <typename T>
void StackWithMax<T>::push(const T &val) {
    if (isEmpty()) {
        stk_max.push_back(val);
    } else {
        T max_num = val > stk_max.back() ? val : stk_max.back();
        stk_max.push_back(max_num);
    }
    vec.push_back(val);
}

template <typename T>
T StackWithMax<T>::pop() {
    if (isEmpty())
        return T();
    T temp = vec.back();
    vec.pop_back();
    stk_max.pop_back();
    return temp;
}



#endif //WEEK2_STACKWITHMAX_H
