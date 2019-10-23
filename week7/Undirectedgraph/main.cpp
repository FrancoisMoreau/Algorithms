#include <iostream>
#include <fstream>
#include <stack>
#include "Udgraph.h"
#include "DepthFirstPath.h"
#include "BreathFirstPath.h"
#include "ConnectedComponents.h"

using std::cout;
using std::endl;

int main() {
    std::ifstream infile("../tinyG.txt");
    if (!infile)
        std::cerr << "NO INPUT FILE\n";
    Udgraph mygraph(infile);
//    std::string res = mygraph.toString();
//    cout << res << endl;
    DepthFirstPath pathof0(&mygraph, 0);
    cout << "path from 0 to 3: " << pathof0.hasPathTo(3) << endl;
    cout << "path from 0 to 9: " << pathof0.hasPathTo(9) << endl;
    std::stack<int> pathto3 = pathof0.pathTo(3);
    while (!pathto3.empty()) {
        cout << pathto3.top() <<  " ";
        pathto3.pop();
    }

    BreathFirstPath pathof10(&mygraph, 10);
    cout << "\n\npath from 10 to 12: " << pathof10.hasPathTo(12) << endl;
    std::stack<int> pathto12 = pathof10.pathTo(12);
    while (!pathto12.empty()) {
        cout << pathto12.top() << " ";
        pathto12.pop();
    }

    ConnectedComponents cc(mygraph);
    cout << "\n\n 1 - 3 : " << cc.connected(1, 3) << endl;
    cout << " 1 - 7 : " << cc.connected(1, 7) << endl;
    cout << " count: " << cc.get_count() << endl;


    return 0;
}