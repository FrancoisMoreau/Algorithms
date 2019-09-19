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

void nextPermutation(std::vector<int> &nums) {
    if (nums.size() == 1)
        return;
    int biggest = nums.back();
    std::vector<int> tail;
    auto r_iter = nums.rbegin();
    for (; r_iter != nums.rend(); ++r_iter) {
        tail.push_back(*r_iter);
        if (biggest > *r_iter) break;
    }
    std::sort(tail.begin(), tail.end());
    auto it_first = std::upper_bound(tail.begin(), tail.end(), *r_iter);
    std::swap(*it_first, *tail.begin());
    std::copy(tail.begin(), tail.end(), r_iter.base() - 1);
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


    cout << "\n\nProblem 31: Next Permutation: \n";
    std::vector<int> pervec{1, 1};
    nextPermutation(pervec);
    for (auto &i : pervec)
        cout << i << " ";
    cout << endl;

    return 0;
}