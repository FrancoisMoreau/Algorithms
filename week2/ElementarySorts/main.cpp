#include <iostream>
#include <random>
#include <chrono>

#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#define ARR_LEN 10000

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

int main() {
    std::default_random_engine e;
    std::uniform_int_distribution<int> u(0, ARR_LEN);

    std::vector<int> StdSortVec, SelSortVec, InserSortVec, ShellSortVec;
    for (size_t i = 0; i < ARR_LEN; ++i) {
        StdSortVec.push_back(u(e));
    }
    SelSortVec = StdSortVec;
    InserSortVec = StdSortVec;
    ShellSortVec = StdSortVec;

    TimeVar t1 = timeNow();
    std::sort(StdSortVec.begin(), StdSortVec.end());
    TimeVar t2 = timeNow();

    std::cout << "STL sort: " << duration(t2 - t1) << " ms\n";

    t1 = timeNow();
    SelectionSort(SelSortVec);
    t2 = timeNow();
    std::cout << "Selection sort: " << duration(t2 - t1) << " ms\n";

    t1 = timeNow();
    InsertionSort(InserSortVec);
    t2 = timeNow();
    std::cout << "Insertion sort: " << duration(t2 - t1) << " ms\n";

    t1 = timeNow();
    ShellSort(ShellSortVec);
    t2 = timeNow();
    std::cout << "Shell sort: " << duration(t2 - t1) << " ms\n";

    for (size_t i = 0; i < ARR_LEN; ++i) {
        if (SelSortVec[i] != StdSortVec[i])
            std::cout << " not same !\n";
        if (InserSortVec[i] != StdSortVec[i])
            std::cout << " not same !\n";
        if (ShellSortVec[i] != StdSortVec[i])
            std::cout << " not same !\n";
    }

    return 0;
}