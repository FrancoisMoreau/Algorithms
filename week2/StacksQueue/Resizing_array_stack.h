//
// Created by brayden on 2019-08-19.
//

#ifndef STACKSQUEUE_RESIZING_ARRAY_STACK_H
#define STACKSQUEUE_RESIZING_ARRAY_STACK_H

#include <vector>

template <typename T>
class VectorStack {
private:
    T _top;
    std::vector<T> rest;
    bool empty = true;
public:
    void pop() {
        if (rest.empty()) {
            empty = true;
            _top = T();
        } else {
            _top = rest.back();
            rest.pop_back();
        }
    }

    void push(const T &t) {
        if (empty) {
            empty = false;
        } else {
            rest.push_back(_top);
        }
        _top = t;
    }

    T top() const {
        return _top;
    }

    T &top_ref() {
        return _top;
    }

    const T &top_ref() const {
        return _top;
    }

    bool IsEmpty() const {
        return empty;
    }
};

#endif //STACKSQUEUE_RESIZING_ARRAY_STACK_H
