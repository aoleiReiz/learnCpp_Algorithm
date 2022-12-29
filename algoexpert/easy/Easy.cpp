//
// Created by aolei.bao on 12/30/2022.
//

#include "Easy.h"

vector<int> Easy::twoNumberSum(vector<int> array, int targetSum) {
    unordered_set<int> set;
    for (auto & i : array){
        auto rem = targetSum - i;
        if (set.find(rem) != set.end()){
            return vector<int>({i, rem});
        }else{
            set.insert(i);
        }
    }
    return vector<int>();
}
