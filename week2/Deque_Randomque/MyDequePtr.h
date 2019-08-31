//
// Created by brayden on 2019-08-31.
//

#ifndef DEQUE_RANDOMQUE_MYDEQUEPTR_H
#define DEQUE_RANDOMQUE_MYDEQUEPTR_H

#include "MyDeque.h"

/*
template <typename T>
class MyDequePtr {
public:
    MyDequePtr() = default;
    MyDequePtr(MyDeque<T> &a) : wptr(a.first) {}
    Node &operator*() const {
        auto p = check(0, "dereference on an empty ptr");
        return p;
    };
    MyDequePtr &operator++();
    MyDequePtr &operator--();
private:
    std::weak_ptr<Node> wptr;
    std::shared_ptr<Node> check(int direct, const std::string &) const;
};

template <typename T>
std::shared_ptr<Node<T>> MyDequePtr<T>::check(int direct, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbounded MyDequePtr");
    return ret;
}

template <typename T>
MyDequePtr<T> &MyDequePtr<T>::operator++ {
        auto p = check(0, "increment past end of MyDeque");
        wptr = p->next;
}
*/


#endif //DEQUE_RANDOMQUE_MYDEQUEPTR_H
