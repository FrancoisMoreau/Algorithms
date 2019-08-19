//
// Created by brayden on 2019-08-19.
//

#ifndef STACKSQUEUE_LINKED_LIST_QUEUE_H
#define STACKSQUEUE_LINKED_LIST_QUEUE_H

#include <stdexcept>

template <typename T>
class LinkedQueue {
private:
    struct Node {
        T val;
        Node *next;
        Node(const T &val) : val(val), next(nullptr) {}
    };
    Node *first = nullptr, *last = nullptr;
public:
    bool isEmpty() { return first == nullptr; }
    void enqueue(const T &val);
    T dequeue();
    ~LinkedQueue();
};

template <typename T>
void LinkedQueue<T>::enqueue(const T &val) {
    Node *old_last = last;
    last = new Node(val);
    if (isEmpty()) first = last;
    else old_last->next = last;
}

template <typename T>
T LinkedQueue<T>::dequeue() {
    if (isEmpty())
        throw std::range_error("dequeue on an empty queue");
    T tmp_val = first->val;
    Node *to_delete = first;
    first = first->next;
    if (isEmpty()) last = nullptr;
    delete to_delete;
    return tmp_val;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    while (!isEmpty())
        dequeue();
}


#endif //STACKSQUEUE_LINKED_LIST_QUEUE_H
