//
// Created by aolei.bao on 1/10/2023.
//

#ifndef LEARNCPP_ALGORITHM_EASYLAST6_H
#define LEARNCPP_ALGORITHM_EASYLAST6_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class EasyLast6 {
public:
    bool isPalindrome(string str);

    string caesarCypherEncryptor(string str, int key);

    string runLengthEncoding(string str);

    bool generateDocument(string characters, string document);

    int firstNonRepeatingCharacter(string string);

    vector<vector<string>> semordnilap(vector<string> words);
};


#endif //LEARNCPP_ALGORITHM_EASYLAST6_H
