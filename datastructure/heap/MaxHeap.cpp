//
// Created by Administrator on 2022/7/9.
//

#include "MaxHeap.h"

template<typename Item>
int MaxHeap<Item>::size() {
    return count;
}

template<typename Item>
bool MaxHeap<Item>::isEmpty() {
    return false;
}



template<typename Item>
void MaxHeap<Item>::shiftUp(int k) {
    while (k > 1 && data[k/2] < data[k]){
        int temp = data[k/2];
        data[k/2] = data[k];
        data[k] = temp;
        k /= 2;
    }
}

template<typename Item>
void MaxHeap<Item>::insert(Item item) {

}
