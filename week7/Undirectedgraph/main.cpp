#include <iostream>
#include <fstream>
#include "Udgraph.h"


using std::cout;
using std::endl;

int main() {
    std::ifstream infile("../tinyG.txt");
    if (!infile)
        std::cerr << "NO INPUT FILE\n";
    Udgraph mygraph(infile);
    std::string res = mygraph.toString();
    cout << res << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}