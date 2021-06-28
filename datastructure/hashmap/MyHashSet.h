//
// Created by Acer on 6/25/2021.
//

#ifndef LEARNCPP_ALGORITHM_MYHASHSET_H
#define LEARNCPP_ALGORITHM_MYHASHSET_H

#include <vector>
using namespace std;

class MyHashSet {
/** Initialize your data structure here. */
private:
    vector<int> KeyVector;
public:
    MyHashSet() {

    }

    void add(int key) {
        if (!contains(key)){
            KeyVector.push_back(key);
        }
    }

    void remove(int key) {
        int index = -1;
        for (int i = 0; i < KeyVector.size(); ++i) {
            if (KeyVector[i] == key){
                index = i;
                break;
            }
        }
        if (index != -1)
            KeyVector.erase(KeyVector.begin() + index);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for (int i = 0; i < KeyVector.size(); ++i) {
            if (KeyVector[i] == key)
                return true;
        }
        return false;
    }
};


#endif //LEARNCPP_ALGORITHM_MYHASHSET_H
