//
// Created by brayden on 2020-01-13.
//

#include "WordNet.h"
#include <fstream>
#include <exception>
#include <sstream>

WordNet::WordNet(const std::string &synsets, const std::string &hypernyms_arg) {
    std::ifstream synsets_input(synsets), hypernyms_input(hypernyms_arg);
    if (!synsets_input)
        throw std::invalid_argument("Invalid input synsets file!\n");
    csv_parser(synsets_input, all_nouns);
    if (!hypernyms_input)
        throw std::invalid_argument("Invalid input hypernyms file!\n");
    csv_parser(hypernyms_input, adj);
}

int WordNet::csv_parser(std::istream &is, std::vector<std::string> &noun) {
    std::string line;
    while(getline(is, line)) {
        noun.push_back(line.substr(line.find(',') + 1, line.rfind(',') - line.find(',') - 1));
        int line_no = std::stoi(line.substr(0, line.find(',')));
        std::istringstream word_set(noun.back());
        std::string parsed_word;
        while (getline(word_set, parsed_word, ' ')) {
            word_map.insert({parsed_word, line_no});
        }
    }
    return 0;
}

int WordNet::csv_parser(std::istream &is, std::vector<std::vector<int>> &hypernym_arg) {
    std::string line;
    while (getline(is, line)) {
        line = line.substr(line.find(',') + 1);
        std::istringstream is_string(line);
        std::vector<int> temp;
        while (getline(is_string, line, ',')) {
            temp.push_back(std::stoi(line));
        }
        adj.push_back(temp);
    }
    return 0;
}

int WordNet::distance(const std::string &nounA, const std::string &nounB) {
    if (!isNoun(nounA) || !isNoun(nounB)) {
        if (!isNoun(nounA)) printf("No %s!\n", nounA.c_str());
        if (!isNoun(nounB)) printf("No %s!\n", nounB.c_str());
        throw std::invalid_argument("No this noun is the WordNet!\n");
    }
    int idx_A = word_map[nounA];
    int idx_B = word_map[nounB];
    SAP shortest_path(this);
    return shortest_path.length(idx_A, idx_B);
}