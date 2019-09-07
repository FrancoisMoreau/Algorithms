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
    for (int i = 0; i < 20; ++i) {
        int key = get_random(20);
        keysvec.push_back(key);
        binarytree.put(key, std::string("aa") + std::to_string(key));
    }

    cout << "input order: ";
    for (auto &i : keysvec)
        cout << i  << " ";
    cout << endl;
    cout << "sorted order: ";
    std::sort(keysvec.begin(), keysvec.end());
    for (auto &i : keysvec)
        cout << i << " ";
    cout << endl;
    int key_to_delete = keysvec[10];

    cout << "largest key: " << binarytree.max() << endl;
    cout << "smallest key: " << binarytree.min() << endl;
    cout << "value for smallest: " << binarytree.get(binarytree.min()) << endl;
    cout << "floor for largest key -1: " << binarytree.floor(binarytree.max() - 1) << endl;
    cout << "ceiling for smallest key +1: " << binarytree.ceiling(binarytree.min() + 1) << endl;
    cout << "size for tree: " << binarytree.size() << endl;
    cout << "rank for largest: " << binarytree.rank(binarytree.max()) << endl;
    cout << "\nkey at rank 2: " << binarytree.select(2) << endl;

    cout << "\nBST => Queue: \n";
    std::queue<int> q = binarytree.keys();
    int q_size = q.size();
    for (int i = 0; i < q_size; ++i) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\nNow delete min, deleted queue: \n";
    binarytree.delMin();
    q = binarytree.keys();
    q_size = q.size();
    for (int i = 0; i < q_size; ++i) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\nNow delete key " << key_to_delete << " : \n";
    binarytree.erase(key_to_delete);

    q = binarytree.keys();
    q_size = q.size();
    for (int i = 0; i < q_size; ++i) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}