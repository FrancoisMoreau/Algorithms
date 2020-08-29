//
// Created by brayden on 2020-08-28.
//

#ifndef MST_EDGE_H
#define MST_EDGE_H

#include <iostream>


class Edge {
public:
    Edge() = default;
    Edge(int v, int w, double weight) : v(v), w(w), weight(weight) {}
    int either() const {
        return v;
    }
    int other(int vertex) const {
        if (vertex == v) return w;
        else return v;
    }
    double get_weight() const {
        return weight;
    }

private:
    int v, w;
    double weight;
};



std::ostream &print(std::ostream &, const Edge &);


#endif //MST_EDGE_H
