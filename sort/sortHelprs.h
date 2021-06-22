//
// Created by Acer on 6/15/2021.
//

#ifndef LEARNCPP_ALGORITHM_SORTHELPRS_H
#define LEARNCPP_ALGORITHM_SORTHELPRS_H

#include <iostream>
#include <cassert>

namespace SortTestHelpers{
    int * generateRandomIntegerArray(int N, int rangeL, int rangeR){
        int * arr = new int [N];
        assert(rangeR >= rangeL);
        for (int i = 0; i < N; ++i) {

            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
}

#endif //LEARNCPP_ALGORITHM_SORTHELPRS_H
