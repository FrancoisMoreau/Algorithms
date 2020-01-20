//
// Created by brayden on 2020-01-13.
//

#ifndef WORDNET_WORDNET_H
#define WORDNET_WORDNET_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "Digraph.h"
#include "SAP.h"

class WordNet : Digraph {
public:
    WordNet(const std::string &synsets, const std::string &hypernyms);
    std::vector<std::string>::const_iterator cbegin() const { return all_nouns.cbegin(); }
    std::vector<std::string>::const_iterator cend() const { return all_nouns.cend(); }
    int get_size() const { return all_nouns.size(); }
    bool isNoun(const std::string &word) { return word_map.find(word) != word_map.end(); }
    int distance(const std::string &nounA, const std::string &nounB);

private:
    int csv_parser(std::istream &is, std::vector<std::string> &noun);
    int csv_parser(std::istream &is, std::vector<std::vector<int>> &hypernym_arg);
    std::vector<std::string> all_nouns;
    std::map<std::string, int> word_map;
//    std::vector<std::vector<int>> hypernyms;

};


#endif //WORDNET_WORDNET_H
