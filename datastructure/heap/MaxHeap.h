//
// Created by Administrator on 2022/7/9.
//

#ifndef LEARNCPP_ALGORITHM_MAXHEAP_H
#define LEARNCPP_ALGORITHM_MAXHEAP_H

#include <iostream>

using namespace std;

template<typename Item>
class MaxHeap {
private:
    Item * data;
    int count;
    int capacity;

    void shiftUp(int k);
public:
    MaxHeap( int capacity){
        data = new Item[capacity + 1];
        count = 0;
        this -> capacity = capacity;
    }

    ~MaxHeap(){
        delete []data;
    }

    int size();
    bool isEmpty();
    void insert(Item item);
};





#endif //LEARNCPP_ALGORITHM_MAXHEAP_H
