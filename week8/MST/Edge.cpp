//
// Created by brayden on 2020-08-28.
//

#include "Edge.h"

std::ostream &print(std::ostream &os, const Edge &e) {
    int v = e.either();
    int w = e.other(v);
    os << "(" << v << ", " << w << ") " << e.get_weight() << std::endl;
    return os;
}
