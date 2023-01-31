//
// Created by 包傲磊 on 2023/2/1.
//

#ifndef LEARNCPP_ALGORITHM_DAY19_H
#define LEARNCPP_ALGORITHM_DAY19_H
# include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string decodeMessage(string key, string message) {
    unordered_map<char, char>keyMap;
    const string chars{"abcdefghijklmnopqrstuvwxyz"};
    int idx = 0;
    for (auto c: key) {
        if (c == ' '){
            continue;
        }
        if(keyMap.find(c) == keyMap.end()){
            keyMap[c] = chars[idx++];
        }
    }
    string ret;
    for(char c : message){
        if (c == ' '){
            ret.push_back(c);
        }else{
            ret.push_back(keyMap[c]);
        }
    }
    return ret;
}

#endif //LEARNCPP_ALGORITHM_DAY19_H
