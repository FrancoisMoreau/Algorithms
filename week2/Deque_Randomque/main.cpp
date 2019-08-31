#include <iostream>
#include "MyDeque.h"

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



    return 0;
}