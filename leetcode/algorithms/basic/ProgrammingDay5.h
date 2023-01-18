//
// Created by 包傲磊 on 2023/1/18.
//

#ifndef LEARNCPP_ALGORITHM_PROGRAMMINGDAY5_H
#define LEARNCPP_ALGORITHM_PROGRAMMINGDAY5_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aIdx = a.size() - 1;
        int bIdx = b.size() - 1;
        int exceedDigit = 0;
        vector<int> digits;
        while (aIdx >= 0 || bIdx >= 0) {
            int addResult = exceedDigit;
            if (aIdx < 0) {
                addResult += b[bIdx] - '0';
                bIdx--;
            } else if (bIdx < 0) {
                addResult += a[aIdx] - '0';
                aIdx--;
            } else {
                addResult += (a[aIdx] - '0') + (b[bIdx] - '0');
                aIdx--;
                bIdx--;
            }
            digits.push_back(addResult % 2);
            exceedDigit = addResult / 2;
        }
        if (exceedDigit > 0){
            digits.push_back(exceedDigit);
        }
        string  ans = "";
        for (int i = digits.size() - 1; i >=0; --i) {
            ans += to_string(digits[i]);
        }
        return ans;
    }

    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> kDigits;
        while (k > 0){
            kDigits.push_back(k % 10);
            k /= 10;
        }
        int left = 0, right = kDigits.size() - 1;
        while (left < right){
            int temp = kDigits[left];
            kDigits[left] = kDigits[right];
            kDigits[right] = temp;
            left ++;
            right --;
        }
        int aIdx = num.size() - 1;
        int bIdx = kDigits.size() - 1;
        int exceedDigit = 0;
        vector<int> digits;
        while (aIdx >= 0 || bIdx >= 0) {
            int addResult = exceedDigit;
            if (aIdx < 0) {
                addResult += kDigits[bIdx];
                bIdx--;
            } else if (bIdx < 0) {
                addResult += num[aIdx];
                aIdx--;
            } else {
                addResult += num[aIdx] + kDigits[bIdx];
                aIdx--;
                bIdx--;
            }
            digits.push_back(addResult % 10);
            exceedDigit = addResult / 10;
        }
        if (exceedDigit > 0){
            digits.push_back(exceedDigit);
        }
        left = 0, right = digits.size() - 1;
        while (left < right){
            int temp = digits[left];
            digits[left] = digits[right];
            digits[right] = temp;
            left ++;
            right --;
        }
        return digits;
    }
};

#endif //LEARNCPP_ALGORITHM_PROGRAMMINGDAY5_H
