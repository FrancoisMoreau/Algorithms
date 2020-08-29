#include <iostream>
#include <fstream>

#include "Edgeweightedgraph.h"
#include "KruskalMST.h"
#include "LazyPrimMST.h"

using namespace std;

int main() {
    ifstream in("../tinyEWG.txt");
    if (!in)
        std::cerr << "NO INPUT !\n";
    Edgeweightedgraph mygraph(in);

    cout << "Kruskal's algorithm: \n";
    KruskalMST mst(&mygraph);
    queue<Edge> mst_res = mst.edges();
    while (!mst_res.empty()) {
        print(cout, mst_res.front());
        mst_res.pop();
    }

    cout << "\nLazy Prim's Algorithm:\n";

    LazyPrimMST lazy(&mygraph);
    queue<Edge> lazy_res = lazy.get_mst();
    while (!lazy_res.empty()) {
        print(cout, lazy_res.front());
        lazy_res.pop();
    }


    return 0;
}