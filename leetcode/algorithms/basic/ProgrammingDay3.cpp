//
// Created by aolei.bao on 1/16/2023.
//

#include "ProgrammingDay3.h"

int ProgrammingDay3::evalRPN(vector<string> &tokens) {
    vector<int> stack;
    for (auto & token : tokens){
        if (isdigit(token[0]) || token.size() > 1){
            stack.push_back(stoi(token));
        }else{
            int num2 = stack.at(stack.size() - 1);
            stack.pop_back();
            int num1 = stack.at(stack.size() - 1);
            stack.pop_back();
            int result = operation(num1, num2, token[0]);
            stack.push_back(result);
        }
    }
    return stack.at(0);
}

int ProgrammingDay3::operation(int num1, int num2, char ops) {
    switch (ops) {
        case '+':
            return num1 + num2;
            break;
        case '-':
            return num1 - num2;
            break;
        case '*':
            return num1 * num2;
            break;
        case '/':
            return num1 / num2;
            break;
        default:
            break;
    }
    return 0;
}

vector<int> ProgrammingDay3::plusOne(vector<int> &digits) {
    int exceedDigit = 0;
    vector<int>res;
    for(int i = digits.size() - 1; i>= 0; --i){
        int digit = digits[i] + exceedDigit;
        if (i == digits.size() - 1){
            digit ++;
        }
        res.push_back(digit % 10);
        exceedDigit = digit / 10;
    }
    if (exceedDigit > 0){
        res.push_back(1);
    }
    int left = 0, right = res.size() - 1;
    while (left < right){
        int temp = res[left];
        res[left] = res[right];
        res[right] = temp;
        left ++;
        right --;
    }

    return res;
}
