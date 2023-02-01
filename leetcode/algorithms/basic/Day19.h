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

class AuthenticationManager {
private:
    unordered_map<string, int> auth;
    int t;
public:
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        auth[tokenId] = currentTime + t;
    }

    void renew(string tokenId, int currentTime) {
        auto iter = auth.find(tokenId);
        if (iter != auth.end() && iter->second > currentTime){
            iter->second = currentTime + t;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto iter: auth) {
            if(iter.second > currentTime){
                count ++;
            }
        }
        return count;
    }
};


struct Node{
    int val;
    Node * next;
    Node(int v):val(v), next(nullptr){}
};

class MyLinkedList {
private:
    Node * head;
    Node * tail;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size || size == 0){
            return -1;
        }
        int count = 0;
        Node * p = head;
        while (count < index){
            p = p->next;
            count ++;
        }
        return p->val;
    }

    void addAtHead(int val) {
        if (head == nullptr){
            head = new Node(val);
            tail = head;
        }else{
            Node *p = new Node(val);
            p->next = head;
            head = p;
        }
        size++;
    }

    void addAtTail(int val) {
        if (tail == nullptr){
            tail = new Node(val);
            head = tail;
        }else{
            tail->next = new Node(val);
            tail = tail->next;
        }
        size ++;
    }

    void addAtIndex(int index, int val) {
        if (index > size){
            return;
        }
        if (index <= 0){
            addAtHead(val);
        }else if(index == size){
            addAtTail(val);
        }else{
            Node * prev = head;
            int count = 0;
            while (count < index - 1){
                prev = prev->next;
                count ++;
            }
            Node * temp = prev->next;
            prev->next = new Node(val);
            prev->next->next = temp;
            size ++ ;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size){
            return;
        }
        Node * dummyHead = new Node(-1);
        dummyHead -> next = head;
        int count = 0;
        Node * prev = dummyHead;
        while (count < index){
            prev = prev->next;
            count ++;
        }
        Node * temp = prev->next;
        prev->next = temp -> next;
        head = dummyHead->next;
        if (index == size - 1){
            tail = prev;
        }
        size --;
    }

    void printList(){
        cout << size << endl;
        Node *p = head;
        while (p){
            cout << p->val << " -> ";
            p = p->next;
        }
        cout << endl;
    }
};

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    // 找到公共前缀
    while (left < right) {
        left >>= 1;
        right >>= 1;
        ++shift;
    }
    return left << shift;
}



#endif //LEARNCPP_ALGORITHM_DAY19_H
