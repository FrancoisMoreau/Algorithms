#include <iostream>
#include <fstream>
#include <sstream>

#include "WordNet.h"
#include "Digraph.h"
#include "SAP.h"
#include "Outcast.h"


using std::cout;
using std::endl;

int main() {
    std::ifstream input("../synsets.txt");
    WordNet word_graph("../synsets.txt", "../hypernyms.txt");
    cout << "word graph size: " << word_graph.get_size() << endl;
    word_graph.distance("cat", "cat");

    Outcast mytest(&word_graph);

    std::vector<std::string> outcast5{"horse", "zebra", "cat", "bear", "table"};
    cout << "outcase5: " << mytest.outcast(outcast5) << endl;

    std::vector<std::string> outcast8 {"water", "soda", "bed", "orange_juice", "milk", "apple_juice", "tea", "coffee"};
    cout << "outcase: " << mytest.outcast(outcast8) << endl;
    

//    std::ifstream test_in("../digraph1.txt");
//    Digraph dg1(test_in);
//    SAP test_sap(&dg1);
//    cout << "\n Test for SAP class: \n";
//    cout << " 3, 11 ancestor: " << test_sap.ancestor(3, 11) << "   len: " << test_sap.length(3, 11)<< endl;
//    cout << " 9, 12 ancestor: " << test_sap.ancestor(12, 9) << "   len: " << test_sap.length(12, 9)<< endl;
//    cout << " 7, 2 ancestor: " << test_sap.ancestor(7, 2) << "   len: " << test_sap.length(7, 2)<< endl;
//    cout << " 1, 6 ancestor: " << test_sap.ancestor(1, 6) << "   len: " << test_sap.length(1, 6)<< endl;
//    cout << " 3, 3 ancestor: " << test_sap.ancestor(3, 3) << "   len: " << test_sap.length(3, 3)<< endl;

    return 0;
}