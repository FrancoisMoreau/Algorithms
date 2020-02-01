//
// Created by brayden on 2020-01-19.
//

#include "Outcast.h"

std::string Outcast::outcast(const std::vector<std::string> &nouns) {
    int size = nouns.size();

    std::vector<int> distance_sum(size, 0);
    for (int i = 0; i < size; ++i) {
        for (auto &j : nouns)
            distance_sum[i] += word_graph->distance(nouns[i], j);
    }
//    for (auto &i : distance_sum) {
//        printf("dis: %d\n", i);
//    }
//    printf("max: %s\n", nouns[*(std::max_element(distance_sum.begin(), distance_sum.end()))].c_str());
    return nouns[(std::max_element(distance_sum.begin(), distance_sum.end())) - distance_sum.begin()];
}