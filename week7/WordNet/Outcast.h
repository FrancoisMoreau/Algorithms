//
// Created by brayden on 2020-01-19.
//

#ifndef WORDNET_OUTCAST_H
#define WORDNET_OUTCAST_H

#include "WordNet.h"

class Outcast {
public:
    Outcast(WordNet *pt) : word_graph(pt) { }
    std::string outcast(const std::vector<std::string> &nouns);

private:
    WordNet *word_graph;


};


#endif //WORDNET_OUTCAST_H
