#include <iostream>

#include "leetcode/algorithms/basic/Day20.h"

using namespace std;

int main() {
    MyCircularQueue myCircularQueue(3);
    cout<< myCircularQueue.enQueue(1)<<endl;
    cout<< myCircularQueue.enQueue(2)<<endl;
    cout<< myCircularQueue.enQueue(3)<<endl;
    cout<< myCircularQueue.enQueue(4)<<endl;
    cout<< myCircularQueue.Rear()<<endl;
    return 0;
}
