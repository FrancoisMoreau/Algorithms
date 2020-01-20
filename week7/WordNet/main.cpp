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
    cout << "table : " << word_graph.isNoun("table") << endl;
    cout << "horse :" << word_graph.isNoun("horse") << endl;
    cout << "cat :" << word_graph.isNoun("cat") << endl;
    word_graph.distance("cat", "cat");


    std::vector<std::string> outcast8 {"water", "soda", "bed", "orange_juice", "milk", "apple_juice", "tea", "coffee"};
    Outcast mytest(&word_graph);
    cout << "outcase: " << mytest.outcast(outcast8) << endl;


    std::ifstream test_in("../digraph1.txt");
    Digraph dg1(test_in);
    SAP test_sap(&dg1);
    cout << "\n Test for SAP class: \n";
    cout << " 3, 11 ancestor: " << test_sap.ancestor(3, 11) << "   len: " << test_sap.length(3, 11)<< endl;
    cout << " 9, 12 ancestor: " << test_sap.ancestor(12, 9) << "   len: " << test_sap.length(12, 9)<< endl;
    cout << " 7, 2 ancestor: " << test_sap.ancestor(7, 2) << "   len: " << test_sap.length(7, 2)<< endl;
    cout << " 1, 6 ancestor: " << test_sap.ancestor(1, 6) << "   len: " << test_sap.length(1, 6)<< endl;
    cout << " 3, 3 ancestor: " << test_sap.ancestor(3, 3) << "   len: " << test_sap.length(3, 3)<< endl;

//    std::string csv = "the,cat,sat,on,the,mat";
//    std::istringstream buffer( csv );
//    std::string token;
//
//    while( std::getline( buffer, token, ',' ) )
//    {
//        std::cout << token << std::endl;
//    }

//    std::string ss = "my name is hey!";
//    std::istringstream s2(ss);
//    std::vector<std::string> string_vec(std::istream_iterator<std::string>(s2), std::istream_iterator<std::string>());
//    cout <<  string_vec()
//    for (auto &m2 : string_vec) {
//        cout << m2 << " !!!" << endl;
//    }

//    std::string ss = "1 2 5 6";
//    std::istringstream s2(ss);
//    std::vector<int> string_vec( std::istream_iterator<int>(s2), std::istream_iterator<int>() );

//    cout << string_vec.size() << endl;
//    for (auto &m2 : string_vec) {
//        cout << m2 << " !!!" << endl;
//    }

//    std::string parsed,input="text to be parsed";
//    std::stringstream input_stringstream(input);
//
//    while (getline(input_stringstream,parsed,' '))
//    {
//        cout << input_stringstream.str() << endl;
//        cout << parsed << endl;
//        // do some processing.
//    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}