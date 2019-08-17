//
// Created by brayden on 2019-08-17.
//

#ifndef INTERVIEWQUESTIONS_SUCCESSORDEL_H
#define INTERVIEWQUESTIONS_SUCCESSORDEL_H

#include "UFCanonical.h"

class SuccessorDel : public UFCanonical {
public:
    SuccessorDel(int n) : UFCanonical(n) {};
    void remove(int n);
};


#endif //INTERVIEWQUESTIONS_SUCCESSORDEL_H
