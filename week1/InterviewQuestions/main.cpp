#include <iostream>
#include <fstream>
#include "SocialNetworkConnectivity.h"
#include "UFCanonical.h"
#include "SuccessorDel.h"

using std::cout;
using std::endl;

int main() {
    std::ifstream input("../timestamp.txt");
    int person;
    input >> person;
    SocialNetCon relation(person);
    int p, q, day = 1;
    while (input) {
        input >> p >> q;
        if (relation.linkPair(p, q))
            break;
        day ++;
    }
    input.close();
    printf("---------------------------------\n"
           "Social Network Connectivity: \n");
    std::cout << "day " << day << std::endl;

    printf("\n---------------------------------\n"
           "Union-find with specific canonical element: \n");
    std::ifstream can_input("../canonical.txt");
    int data;
    can_input >> data;
    UFCanonical ufbig(data);
    int lhs, rhs;
    while (can_input) {
        can_input >> lhs >> rhs;
        ufbig.unite(lhs, rhs);
    }
    can_input.close();
    printf("canonical data of %d is %d\n", 1, ufbig.find(1));
    printf("canonical data of %d is %d\n", 2, ufbig.find(2));
    printf("canonical data of %d is %d\n", 6, ufbig.find(6));
    printf("canonical data of %d is %d\n", 8, ufbig.find(8));

    printf("\n---------------------------------\n"
           "Successor with delete: \n");
    SuccessorDel delelem(10);
    int a[] = {5, 4, 2, 1};
    for (auto &i : a) {
        cout << "delete " << i << ": " << endl;
        delelem.remove(i);
        cout << "successor: " << delelem.find(i) << endl;
    }

    return 0;
}
