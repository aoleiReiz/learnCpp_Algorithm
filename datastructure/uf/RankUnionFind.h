//
// Created by aolei.bao on 3/30/2023.
//

#ifndef LEARNCPP_ALGORITHM_RANKUNIONFIND_H
#define LEARNCPP_ALGORITHM_RANKUNIONFIND_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include <optional>

using namespace std;

class RankUnionFind {
private:
    unordered_map<int, int> parent;
    unordered_map<optional<int>, int> rank;
public:
    void createSet(int value) {
        parent[value] = value;
        rank[value] = 1;
    }

    optional<int> find(int value) {
        auto iter = parent.find(value);
        if (iter == parent.end()){
            return nullopt;
        }
        while (iter->second != iter->first){
            iter -> second = parent[iter->second];
            iter = parent.find(iter->second);
        }
        return iter->second;
    }

    void createUnion(int valueOne, int valueTwo) {
        auto setOne = find(valueOne);
        auto setTwo = find(valueTwo);
        if (setOne == nullopt || setTwo == nullopt){
            return;
        }
        int rankOne = rank[setOne];
        int rankTwo = rank[setTwo];
        if (rankOne == rankTwo){
            parent[setOne.value()] = setTwo.value();
            rank[rankTwo] ++;
        }else if (rankOne < rankTwo){
            parent[setOne.value()] = setTwo.value();
        }else{
            parent[setTwo.value()] = setOne.value();
        }
    }
};


#endif //LEARNCPP_ALGORITHM_RANKUNIONFIND_H
