#include <iostream>
#include <fstream>
#include "DirectedDFS.h"
#include "DepthFirstOrder.h"
#include "KosarajuSharirSCC.h"

int main() {
    std::ifstream input("../tinyDG.txt");
    Digraph tinyDG(input);
    DirectedDFS dgraph_dfs(&tinyDG, 0);
    printf("from 0 to 3: %d\n", dgraph_dfs.visited(3));
    printf("from 0 to 6: %d\n", dgraph_dfs.visited(6));
    printf("path for 0 to 3: \n");
    std::stack<int> path_res = dgraph_dfs.pathto(3);
    while (!path_res.empty()) {
        std::cout << path_res.top() << " -> ";
        path_res.pop();
    }

    printf("\n\nTopological sort in DAG: \n");
    Digraph tinyDG_reversed = tinyDG.reverse();
    DepthFirstOrder dag(&tinyDG_reversed);
    std::stack<int> dag_order = dag.get_reversePost();
    while (!dag_order.empty()) {
        std::cout << dag_order.top() << " -> ";
        dag_order.pop();
    }

    printf("\n\nStrong connected components: \n");
    KosarajuSharirSCC StrongCC(&tinyDG);

    return 0;
}