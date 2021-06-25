//
// Created by aolei.bao on 6/25/2021.
//

#ifndef LEARNCPP_ALGORITHM_MYHASHMAP_H
#define LEARNCPP_ALGORITHM_MYHASHMAP_H

#include <vector>
#include <list>

using namespace std;

class MyHashMap {
private:
    const int BASE = 1000;
    vector<list<int>>keyVector;
    vector<vector<int>>dataVector;

    int hash(int key){
        return key % BASE;
    }

public:
    MyHashMap(){
        keyVector = vector<list<int>>(BASE);
        dataVector = vector<vector<int>>(BASE);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashedKey = hash(key);
        int index = findKey(key);
        if (index == -1){
            keyVector[hashedKey].push_back(key);
            dataVector[hashedKey].push_back(value);
        }else{
            dataVector[hashedKey][index] = value;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashedKey = hash(key);
        int index = findKey(key);
        if (index == -1){
            return -1;
        }else{
            return dataVector[hashedKey][index];
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashedKey = hash(key);
        int index = findKey(key);
        if (index != -1){
            int val = dataVector[hashedKey][index];
            keyVector[hashedKey].remove(key);
            dataVector[hashedKey].erase(dataVector[hashedKey].begin() + index);
        }
    }


    int findKey(int key){
        int index = -1;
        int hashedKey = hash(key);
        int i = 0;
        for (int & it : keyVector[hashedKey]) {
            if (it == key) {
                index = i;
                break;
            }
            i ++;
        }
        return index;
    }


};


#endif //LEARNCPP_ALGORITHM_MYHASHMAP_H
