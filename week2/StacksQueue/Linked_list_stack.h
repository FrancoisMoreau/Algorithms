//
// Created by brayden on 2019-08-19.
//

#ifndef STACKSQUEUE_LINKED_LIST_STACK_H
#define STACKSQUEUE_LINKED_LIST_STACK_H

#include <stdexcept>

template <typename T>
class LinkedStack {
public:
    bool isEmpty() const { return first == nullptr; }
    void push(const T &);
    T pop();
    LinkedStack() : first(nullptr) {}
    ~LinkedStack();

private:
    struct Node {
        T val;
        Node *next;
        Node() : next(nullptr) {}
        Node(const T &val) : val(val) {}
    };
    Node *first = nullptr;
};

template <typename T>
void LinkedStack<T>::push(const T &val) {
    Node *old_first = first;
    first = new Node(val);
    first->next = old_first;
}

template <typename T>
T LinkedStack<T>::pop() {
    if (isEmpty()) {
        throw std::range_error("pop on an empty stack");
    }
    Node *to_delete = first;
    T val = first->val;
    first = first->next;
    delete to_delete;
    return val;
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
    while (!isEmpty())
        pop();
}

#endif //STACKSQUEUE_LINKED_LIST_STACK_H
