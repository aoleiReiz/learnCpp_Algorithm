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

bool EasyLast6::generateDocument(string characters, string document) {
    unordered_map<char, int> counter;
    for (auto & c: characters) {
        auto it = counter.find(c);
        if (it != counter.end()){
            it -> second ++;
        }else{
            counter[c] = 1;
        }
    }
    for (auto & c: document) {
        auto it = counter.find(c);
        if (it == counter.end()){
            return false;
        }
        if (it -> second <= 0){
            return false;
        }
        it -> second --;
    }
    return true;
}

int EasyLast6::firstNonRepeatingCharacter(string string) {
    unordered_map<char, int> counter;
    for (auto & c: string) {
        auto it = counter.find(c);
        if (it != counter.end()){
            it -> second ++;
        }else{
            counter[c] = 1;
        }
    }
    for (int i = 0; i < string.length(); ++i) {
        auto it = counter.find(string[i]);
        if (it -> second == 1){
            return i;
        }
    }
    return -1;
}

vector<vector<string>> EasyLast6::semordnilap(vector<string> words) {
    unordered_set<string> wordSet({words.begin(), words.end()});
    vector<vector<string>>res;
    for (auto & word: words) {
        auto it = wordSet.find(word);
        if (it == wordSet.end()){
            continue;
        }
        wordSet.erase(it);
        string reverseWord = "";
        for (int i = word.size() - 1; i >= 0; --i) {
            reverseWord += word[i];
        }
        auto it2 = wordSet.find(reverseWord);
        if (it2 != wordSet.end()){
            res.push_back(vector<string>({word, reverseWord}));
            wordSet.erase(it2);
        }
    }
    return res;
}
