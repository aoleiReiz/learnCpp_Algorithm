//
// Created by Acer on 7/6/2021.
//

#ifndef LEARNCPP_ALGORITHM_DAY1_H
#define LEARNCPP_ALGORITHM_DAY1_H
#include <string>

using namespace std;

class Solution {
public:
    string compressString(string S) {
        if (S.empty()){
            return S;
        }
        string res;
        char cur = S[0];
        int count = 1;
        for (int i = 1; i < (int)S.length(); ++i) {
            if (S[i] == cur){
                count ++;
            }else{
                res += cur + to_string(count);
                cur = S[i];
                count = 1;
            }
        }
        res = res + cur + to_string(count);
        return res.length() <= S.length() ? res : S;
    }


    bool isFlipedString(string s1, string s2) {
        if (s1 == s2){
            return true;
        }
        if (s1.length() != s2.length()){
            return false;
        }
        return (s1 + s1).find(s2) != std::string::npos;
    }
};
#endif //LEARNCPP_ALGORITHM_DAY1_H
