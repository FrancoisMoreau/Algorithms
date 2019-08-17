#include <iostream>
#include <fstream>
#include "QuickFind.h"
#include "QuickUnion.h"
#include "WeightedQuickUnion.h"

using std::ifstream;
using std::cout;
using std::endl;

int main() {
    ifstream input("../tinyUF.txt");
    int N = 0, p = 0, q = 0;
    input >> N;

    QuickFind UF(N);
    QuickUnion QU(N);
    WeightedQuickUnion WQU(N);


    while (input) {
        input >> p;
        input >> q;
        if (!UF.connected(p, q)) {
            UF.unite(p, q);
            cout << "QuickFind: " << p << " " << q << "  ";
        }
        if (!QU.connected(p, q)) {
            QU.unite(p, q);
            cout << "QuickUnion: " << p << " " << q << "  ";
        }
        if (!WQU.connected(p, q)) {
            WQU.unite(p, q);
            cout << "WeightedQU: " << p << " " << q << endl;
        }
    }



    return 0;
}
