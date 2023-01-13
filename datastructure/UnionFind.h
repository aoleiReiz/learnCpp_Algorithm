//
// Created by aolei.bao on 1/13/2023.
//

#ifndef LEARNCPP_ALGORITHM_UNIONFIND_H
#define LEARNCPP_ALGORITHM_UNIONFIND_H
#include <vector>
#include <iostream>
#include <unordered_map>
#include <optional>

using namespace std;

class UnionFind {
private:
    unordered_map<int, int> map;
    unordered_map<optional<int>, int> rank;
public:
    void createSet(int value);
    optional<int> find(int value);
    void createUnion(int valueOne, int valueTwo);
};


#endif //LEARNCPP_ALGORITHM_UNIONFIND_H
