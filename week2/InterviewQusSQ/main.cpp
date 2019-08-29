#include <iostream>
#include <stack>
#include <queue>

#include "QueueWith2Stacks.h"
#include "StackWithMax.h"

int main() {
    QueueWith2Stacks<int> queue2stk;
    printf("Queue with 2 stack: \n");
    for (int i = 0; i < 20; ++i) {
        queue2stk.push(i);
        if (i % 4 == 0)
            std::cout << queue2stk.pop() << std::endl;
    }

//    printf("Stack with max: \n");
//    StackWithMax<int> stkmax;
//    for (int i = 0; i < 20; ++i) {
//        stkmax.push(i);
//        if (i % 4 == 0) {
//            std::cout << stkmax.pop() << std::endl;
//            std::cout << stkmax.pop() << std::endl;
//            std::cout << stkmax.max() << std::endl;
//        }
//    }

    return 0;
}
