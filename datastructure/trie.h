//
// Created by aolei.bao on 2/8/2023.
//

#ifndef LEARNCPP_ALGORITHM_TRIE_H
#define LEARNCPP_ALGORITHM_TRIE_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node{
    bool isWord;
    unordered_map<char, Node*> next;
public:
    Node(){
        isWord = false;
    }
    Node(bool _isWord, unordered_map<char, Node*> m){
        isWord = _isWord;
        next = m;
    }
};

class Trie {
private:
    Node root;
public:
    Trie() {

    }

    void insert(string word) {
        Node *cur = &root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if ((*cur).next.find(c) == (*cur).next.end()){
                (*cur).next[c] = new Node();
            }
            cur = (*cur).next[c];
        }
        if (!(*cur).isWord){
            (*cur).isWord = true;
        }
    }

    bool search(string word) {
        Node *cur = & root;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if ((*cur).next.find(c) == (*cur).next.end()){
                return false;
            }
            cur = (*cur).next[c];
        }
        return (*cur).isWord;
    }

    bool startsWith(string prefix) {
        Node cur = root;
        for (int i = 0; i < prefix.length(); ++i) {
            char c = prefix[i];
            if (cur.next.find(c) == cur.next.end()){
                return false;
            }
            cur = *cur.next[c];
        }
        return true;
    }
};


#endif //LEARNCPP_ALGORITHM_TRIE_H
