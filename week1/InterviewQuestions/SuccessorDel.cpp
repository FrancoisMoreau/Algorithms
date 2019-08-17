//
// Created by brayden on 2019-08-17.
//

#include "SuccessorDel.h"

void SuccessorDel::remove(int n) {
    unite(n, n + 1);
}