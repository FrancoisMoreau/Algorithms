#include <iostream>
#include <random>
#include <chrono>
#include "MaxPQ.h"
#include "HeapSort.h"

int get_random(int n) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n);
    int dice_roll = distribution(rng);
    return dice_roll;
}

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

const int Arr_Len = 10000;


int main() {
    MaxPQ maxpriq;

    printf("Binary Heap Tree: \n");
    for (int i = 0; i < 20; ++i) {
        maxpriq.insert(get_random(20));
    }
    for (int i = 0; i < 20; ++i) {
        std::cout << maxpriq.delMax() << " ";
    }

    printf("\n\nHeapSort\n");

    std::vector<int> hsort_vec;
    for (int i = 0; i < Arr_Len; ++i) {
        hsort_vec.push_back(get_random(Arr_Len));
    }
    std::vector<int> stl_vec (hsort_vec);

    heap<int> heap;

    TimeVar t1 = timeNow();
    heap.heapsort(hsort_vec);
    TimeVar t2 = timeNow();

    std::cout << "time for HeapSort : " << duration(t2 - t1) << " ms. " << std::endl;


    std::sort(stl_vec.begin(), stl_vec.end());

    for (int i = 0; i < Arr_Len; ++i) {
        if (stl_vec[i] != hsort_vec[i])
            std::cout << "not same\n";
    }

    printf("Success!\n");
    return 0;
}