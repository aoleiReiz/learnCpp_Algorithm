//
// Created by 包傲磊 on 2023/1/4.
//

#include "Maopao.h"

string Maopao::minNumber(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = n - 2; j >= 0 ; --j) {
            if (minNumberCompare(nums.at(j), nums.at(j + 1)) > 0){
                int temp = nums.at(j);
                nums.at(j) = nums.at(j + 1);
                nums.at(j + 1) = temp;
            }
        }
    }
    string res;
    for (auto i: nums) {
        res += to_string(i);
    }
    return res;
}

int Maopao::minNumberCompare(int a, int b) {
    string a_str = to_string(a);
    string b_str = to_string(b);
    string t12 = a_str + b_str;
    string t21 = b_str + a_str;
    stringstream ss;
    long long i_12, i_21;
    ss << t12;
    ss >> i_12;
    ss.clear();
    ss << t21;
    ss >> i_21;
    return i_12 < i_21 ? -1 : (i_12 == i_21 ? 0 : 1);
}

void Maopao::moveZeroes(vector<int> &nums) {
    int k = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums.at(i) != 0){
            nums.at(k++) = nums.at(i);
        }
    }
    for (int i = k; i < n; ++i) {
        nums.at(i) = 0;
    }

}
