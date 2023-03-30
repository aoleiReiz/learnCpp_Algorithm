//
// Created by aolei.bao on 1/13/2023.
//

#include "UnionFind.h"

void UnionFind::createSet(int value) {
    map[value] = value;
    rank[value] = 1;
}

optional<int> UnionFind::find(int value) {
    auto iter = map.find(value);
    if (iter == map.end()){
        return nullopt;
    }
    while (iter->second != iter->first){
        iter -> second = map[iter->second];
        iter = map.find(iter->second);
    }
    return iter->second;
}

void UnionFind::createUnion(int valueOne, int valueTwo) {
    auto setOne = find(valueOne);
    auto setTwo = find(valueTwo);
    if (setOne == nullopt || setTwo == nullopt){
        return;
    }
    int rankOne = rank[setOne];
    int rankTwo = rank[setTwo];
    if (rankOne == rankTwo){
        map[setOne.value()] = setTwo.value();
        rank[rankTwo] ++;
    }else if (rankOne < rankTwo){
        map[setOne.value()] = setTwo.value();
    }else{
        map[setTwo.value()] = setOne.value();
    }
}
