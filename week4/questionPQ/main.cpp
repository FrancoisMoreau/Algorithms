#include <iostream>
#include <random>

#include "DynamicMedian.h"
#include "TaxicabNumber.h"

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
    cout << "Realization of my MaxPQ, MinPQ: " << endl;
    PriorityQueue maxq, minq([](int a, int b) { return a < b; });
    for (int i = 0; i < 20; ++i) {
        int key = get_random(20);
        maxq.insert(key);
        minq.insert(key);
    }

    while (!maxq.isEmpty())
        cout << maxq.delTop() << " ";
    cout << endl;

    while (!minq.isEmpty())
        cout << minq.delTop() << " ";
    cout << endl;

    cout << "\nDynamic Median: \n";
    DynamicMedian dymid;
    for (int i = 0; i < 20; ++i) {
        dymid.insert(i);
    }
    while (!dymid.isEmpty()) {
        cout << dymid.delMid() << " ";
    }
    cout << endl;

    cout << "\n\nTaxicab numbers: \n";

    std::vector<TaxicabNumber> vec_tn;
    find_taxicab_numbers(35, vec_tn);

    return 0;
}