#include <iostream>
#include <random>

#include "SmallArrayMergeSort.h"
#include "CountInversion.h"

const int Arr_Len = 20;

using std::cout;
using std::endl;

int get_random(int n) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n);
    int dice_roll = distribution(rng);
    return dice_roll;
}

int main() {
    printf("Res for small auxilary array merge sort: \n");
    std::vector<int> slaux_vec;
    for (int i = 0; i < Arr_Len; ++i) {
        slaux_vec.push_back(get_random(Arr_Len));
    }

    SmallMS(slaux_vec);

    for (int &i : slaux_vec)
        cout << i << " ";
    cout <<endl;

    printf("\n\nCounting Inversions: \n");
    std::vector<int> count_vec;
    for (int i = 8; i > 0; --i) {
        if (i %2  == 0)
        count_vec.push_back(i);
        else
            count_vec.push_back(1);
    }

    cout << "Inversion: " << count_inversion(count_vec) << endl;

    return 0;
}