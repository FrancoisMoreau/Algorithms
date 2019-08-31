#include <iostream>
#include "MyDeque.h"
#include "RandomizedQueue.h"
#include "SimpleRandomizedQue.h"

using std::cout;
using std::endl;
int main() {
    MyDeque<int> mydq;
    cout << "Deque Realization: \n";
    for (int i = 0; i < 10; ++i) {
        mydq.addFirst(i);
        mydq.addLast(10 + i);
    }
    for (int i = 0 ; i < 5; ++i) {
        cout << mydq.removeFirst() << " ";
        cout << mydq.removeLast() << " ";
    }

    cout << "\n\nRandomized Queue: \n";
    RandomizedQueue<int> rdnq;
    for (int i = 0; i < 10; ++i) {
        rdnq.enque(i);
    }
    for (int i = 0; i < 10; ++i) {
        cout << rdnq.dequeue() << " ";
    }

    cout << "\n\nVector Realized Randomized Queue: \n";
    SimpleRandomizedQueue<int> srq;
    for (int i = 0; i < 10; ++i) {
        srq.enque(i);
    }
    for (int i = 0; i < 10; ++i) {
        cout << srq.dequeue() << " ";
    }

    return 0;
}