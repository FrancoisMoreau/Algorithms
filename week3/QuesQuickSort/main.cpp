#include <iostream>
#include <random>
#include <vector>

#include "NutsBolts.h"
#include "SelectionTwoArrays.h"
#include "DecimalDominants.h"

using std::vector;
using std::cout;
using std::endl;

int get_random(int n) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n);
    int dice_roll = distribution(rng);
    return dice_roll;
}

template <typename T>
void Knuth_shuffle(std::vector<T> &vec) {
    int N = vec.size();
    for (int i = 0; i < N; ++i) {
        std::swap(vec[i], vec[get_random(i)]);
    }
}

int divide(int dividend, int divisor) {
    long abs_divident = abs(long(dividend));
    long abs_divisor = abs(long(divisor));

    long res = 0;
    while (abs_divident >= abs_divisor) {
        long temp_divisor = abs_divisor;
        int key = 1;
        while (abs_divident >= temp_divisor) {
            temp_divisor = abs_divisor << key;
            key += 1;
        }
        key = key - 2;
        res += (long(1) << key);
        abs_divident -= temp_divisor >> 1;

    }
    res = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) ? res : -res;
    res = res > INT32_MAX ? INT32_MAX : res;
    return res;
}

int main() {
    vector<int> nuts;
    vector<char> bolts;
    vector<size_t> position;
    for (int i = 0; i != 26; ++i) {
        nuts.push_back(i);
        bolts.push_back('a' + i);
        position.push_back(i);
    }

    //shuffle the nuts and bolts;
    Knuth_shuffle(nuts);
    Knuth_shuffle(bolts);

    cout << "Nuts and bolts problem: \n";
    for (auto &i : nuts)
        cout << i << " ";
    cout << endl;

    for (auto &j : bolts)
        cout << j << " ";
    cout << endl;


    cout << "after matching: \n";
    NutsBolts(nuts, bolts, position);
    for (auto &i : nuts)
        cout << i << " ";
    cout << endl;

    for (auto &j : bolts)
        cout << j << " ";
    cout << endl;
    for (auto &k : position)
        cout << k << " ";
    cout << endl;

    // Leetcode problem 29
    cout << "\nDivide Two Integers: \n";
    cout << "divide for (10, 3):  " << divide(10, 3) << endl;
    cout << "divide for (7, -3): " << divide(7, -3) << endl;
    cout << "divide for (-2147483648, -1): " << divide(-2147483648, -1) << endl;

    //Selection in two sorted arrays
    cout << "\nSelection in Two sorted arrays: \n";
    std::vector<int> sorted_arr0;
    sorted_arr0.reserve(8);
    std::vector<int> sorted_arr1;
    sorted_arr1.reserve(8);
    for (int i = 0; i < 8; ++i) {
        sorted_arr0.push_back(get_random(100));
    }
    for (int j = 0; j < 8; ++j) {
        sorted_arr1.push_back(get_random(100));
    }
    std::sort(sorted_arr0.begin(), sorted_arr0.end());
    std::sort(sorted_arr1.begin(), sorted_arr1.end());
    int kth = get_random(7) + 1;
    cout << "kth " << kth << endl;

    cout << "My answer: \n";
    cout << selectionTwoSortedArrays(sorted_arr0, sorted_arr1, kth) << endl;

    for (auto &i : sorted_arr0)
        cout << i << " ";
    cout << endl;
    for (auto &i : sorted_arr1)
        cout << i << " ";
    cout << endl;

    std::vector<int> merged(sorted_arr0);
    merged.insert(merged.end(), sorted_arr1.begin(), sorted_arr1.end());
    std::sort(merged.begin(), merged.end());
    cout << "standard answer: " << merged[kth - 1] << endl;

    //Realization for decimal dominats
    cout << "Decimal Deminants: \n";
    std::vector<int> decimal_vec;
    for (int i = 0; i < 10; ++i)
        decimal_vec.push_back(get_random(10));


    for (auto &i : decimal_vec)
        cout << i << " ";
    cout << endl;
    DecimalDominants(decimal_vec);
    for (auto &i : decimal_vec)
        cout << i << " ";
    cout << endl;


    return 0;
}