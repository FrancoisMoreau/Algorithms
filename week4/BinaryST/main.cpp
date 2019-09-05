#include <iostream>
#include <random>
#include <vector>
#include <string>

#include "BinaryST.h"

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
    BST<int, std::string> binarytree;
    std::vector<int> keysvec;

    char val_base = 'a';
    for (int i = 0; i < 10; ++i) {
        int key = get_random(10);
        keysvec.push_back(key);
        binarytree.put(key, std::string("aa") + std::to_string(key));
    }

//    cout << endl;
//    std::sort(keysvec.begin(), keysvec.end());
    cout << "input order: ";
    for (auto &i : keysvec)
        cout << i  << " ";
    cout << endl;
    cout << "sorted order: ";
    std::sort(keysvec.begin(), keysvec.end());
    for (auto &i : keysvec)
        cout << i << " ";
    cout << endl;

    cout << "largest key: " << binarytree.max() << endl;
    cout << "smallest key: " << binarytree.min() << endl;
    cout << "value for smallest: " << binarytree.get(binarytree.min()) << endl;
    cout << "floor for largest: " << binarytree.floor(binarytree.max() - 1) << endl;
    cout << "size for tree: " << binarytree.size() << endl;
    cout << "rank for largest: " << binarytree.rank(binarytree.max()) << endl;

    cout << "BST => Queue: \n";
    std::queue<int> q = binarytree.keys();
    int q_size = q.size();
    for (int i = 0; i < q_size; ++i) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\nkey at rank 2: " << binarytree.select(2) << endl;

    cout << "\nceiling for smallest + 1: " << binarytree.ceiling(binarytree.min() + 1) << endl;
    std::cout << "\n\nHello, World!" << std::endl;
    return 0;
}