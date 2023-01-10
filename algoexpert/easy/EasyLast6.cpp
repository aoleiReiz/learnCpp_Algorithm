//
// Created by aolei.bao on 1/10/2023.
//

#include "EasyLast6.h"

bool EasyLast6::isPalindrome(string str) {
    int left = 0;
    int right = str.size() - 1;
    while (left < right){
        if (str[left] != str[right]){
            return false;
        }
        left ++;
        right --;
    }
    return true;
}

string EasyLast6::caesarCypherEncryptor(string str, int key) {
    string res = "";
    int rotate = key % 26;
    for (int i = 0; i < str.length(); ++i) {
        int charIndex = (str[i] - 'a' + rotate) % 26;
        char newChar = 'a' + charIndex;
        res += newChar;
    }
    return res;
}

string EasyLast6::runLengthEncoding(string str) {
    char prev = str[0];
    char prevCount = 1;
    string res = "";
    for (int i = 1; i < str.length() ; ++i) {
        if (prev == str[i]){
            prevCount += 1;
        }else{
            res += to_string(prevCount);
            res += prev;
            prev = str[i];
            prevCount = 1;
        }
        if (prevCount == 10){
            res += '9';
            res += prev;
            prevCount = 1;
        }
    }
    res += to_string(prevCount);
    res += prev;
    return res;
}
