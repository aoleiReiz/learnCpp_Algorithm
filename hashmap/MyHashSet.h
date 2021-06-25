//
// Created by aolei.bao on 6/25/2021.
//

#ifndef LEARNCPP_ALGORITHM_MYHASHSET_H
#define LEARNCPP_ALGORITHM_MYHASHSET_H
#include <vector>
#include <list>

using namespace std;

class MyHashSet {
private:
    const int BASE = 1000;
    vector<list<int>>data;

    int hash(int key){
        return key % BASE;
    }

public:
    MyHashSet(){
        data = vector<list<int>>(BASE);
    }

    void add(int key){
        int hashedKey = hash(key);
        data[hashedKey].push_back(key);
    }

    void remove(int key){
        int hashedKey = hash(key);
        data[hashedKey].remove(key);
    }

    bool contains(int key){
        int hashedKey = hash(key);
        for (auto it = data[hashedKey].begin(); it != data[hashedKey].end(); it ++) {
            if (*it == key)
                return true;
        }
        return false;
    }
};


#endif //LEARNCPP_ALGORITHM_MYHASHSET_H
