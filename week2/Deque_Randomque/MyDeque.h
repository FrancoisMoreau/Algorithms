//
// Created by brayden on 2019-08-31.
//

#ifndef DEQUE_RANDOMQUE_MYDEQUE_H
#define DEQUE_RANDOMQUE_MYDEQUE_H

#include <memory>

template <typename T>
class MyDequePtr;


template <typename T>
class MyDeque {
    friend class MyDequePtr<T>;
private:
    struct Node {
        T val;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;
        Node(const T &val) : val(val) {}
    };
    std::shared_ptr<Node> first;
    std::shared_ptr<Node> last;
    unsigned qsize = 0;

public:
    MyDeque() = default;
    bool isEmpty() { return qsize == 0; };
    int size() { return qsize; };
    void addFirst(const T &);
    void addLast(const T &);
    T removeFirst();
    T removeLast();
    std::shared_ptr<Node> begin() { return first; };
    std::shared_ptr<Node> end() { return  last; };
};

template <typename T>
void MyDeque<T>::addFirst(const T &val) {
    std::shared_ptr<Node> old_first = first;
    first = std::shared_ptr<Node>(new Node(val));
    if (isEmpty())
        last = first;
    else {
        first->next = old_first;
        old_first->prev = first;
    }
    ++qsize;
}

template <typename T>
void MyDeque<T>::addLast(const T &val) {
    std::shared_ptr<Node> old_last = last;
    last = std::shared_ptr<Node>(new Node(val));
    if (isEmpty())
        first = last;
    else {
        old_last->next = last;
        last->prev = old_last;
    }
    ++qsize;
}

template <typename T>
T MyDeque<T>::removeFirst() {
    if (isEmpty())
        throw std::out_of_range("Cannot remove on an empty deque");
    T val = first->val;
    first = first->next;
    if (qsize == 1)
        last = first;
    --qsize;
    return val;
}

template <typename T>
T MyDeque<T>::removeLast() {
    if (isEmpty())
        throw std::out_of_range("Cannot remove on an empty deque");
    T val = last->val;
    last = last->prev;
    if (qsize == 1)
        first = last;
    --qsize;
    return val;
}


#endif //DEQUE_RANDOMQUE_MYDEQUE_H
