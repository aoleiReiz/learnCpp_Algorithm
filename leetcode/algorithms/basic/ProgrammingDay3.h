//
// Created by aolei.bao on 1/16/2023.
//

#ifndef LEARNCPP_ALGORITHM_PROGRAMMINGDAY3_H
#define LEARNCPP_ALGORITHM_PROGRAMMINGDAY3_H
#include <vector>
#include <string>

using namespace std;

class ProgrammingDay3 {
public:
    int evalRPN(vector<string>& tokens);
    int operation(int num1, int num2, char ops);
    vector<int> plusOne(vector<int>& digits);
};


#endif //LEARNCPP_ALGORITHM_PROGRAMMINGDAY3_H
