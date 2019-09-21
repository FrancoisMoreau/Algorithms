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
//    if (nums.size() == 1)
//        return;
    int biggest = nums.back();
    std::vector<int> tail;
    auto r_iter = nums.rbegin();
    for (; r_iter != nums.rend(); ++r_iter) {
        tail.push_back(*r_iter);
        if (biggest > *r_iter) break;
        else biggest = *r_iter;
    }
    if (r_iter == nums.rend() || *(r_iter - 1) > biggest) {
        std::sort(nums.begin(), nums.end());
        return;
    }
    std::sort(tail.begin(), tail.end());
    auto it_first = std::upper_bound(tail.begin(), tail.end(), *r_iter);
    std::swap(*it_first, *tail.begin());
    std::sort(tail.begin() + 1, tail.end());
    std::copy(tail.begin(), tail.end(), r_iter.base() - 1);
}

void nextPermutation2(std::vector<int> &nums) {
    auto biggest = nums.back();
    auto r_iter = nums.rbegin();
    for (; r_iter != nums.rend(); ++r_iter) {
        if (biggest > *r_iter) break;
        else biggest = *r_iter;
    }
    if (r_iter == nums.rend() || *(r_iter - 1) > biggest) {
//        std::sort(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.end());
        return;
    }
//    std::sort(r_iter.base(), nums.end());
//    auto it_first = std::upper_bound(r_iter.base(), nums.end(), *r_iter);
    auto it_first = std::upper_bound(nums.rbegin(), r_iter, *r_iter);
    std::swap(*it_first, *(r_iter));
//    std::sort(r_iter.base(), nums.end());
    std::reverse(r_iter.base(), nums.end());
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
    std::vector<int> pervec{1, 3, 2};
    nextPermutation2(pervec);
    for (auto &i : pervec)
        cout << i << " ";
    cout << endl;

    return 0;
}