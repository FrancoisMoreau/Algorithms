//
// Created by brayden on 19-8-22.
//

#ifndef WEEK2_QUEUEWITH2STACKS_H
#define WEEK2_QUEUEWITH2STACKS_H

#include <stack>

template <typename T>
class QueueWith2Stacks {
public:
    bool isEmpty() const { return (stk0.empty() && stk1.empty()); }
    void push(const T &);
    T pop();
private:
    std::stack<T> stk0;
    std::stack<T> stk1;
};


template <typename T>
void QueueWith2Stacks<T>::push(const T &t) {
    stk0.push(t);
}

template <typename T>
T QueueWith2Stacks<T>::pop() {
    if (stk1.empty()) {
        while (!stk0.empty()) {
            stk1.push(stk0.top());
            stk0.pop();
        }
    }
    T temp = stk1.top();
    stk1.pop();
    return temp;
}


#endif //WEEK2_QUEUEWITH2STACKS_H
