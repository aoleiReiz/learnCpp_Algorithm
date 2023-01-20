#include <iostream>
#include "leetcode/algorithms/basic/Day7.h"
using namespace std;

int main() {
    Node * ptr1 = new Node(1);
    Node * ptr2 = new Node(2);
    Node * ptr3 = new Node(3);
    Node * ptr4 = new Node(4);
    Node * ptr5 = new Node(5);
    Node * ptr7 = new Node(7);
    ptr1->left = ptr2;
    ptr1->right = ptr3;
    ptr2->left = ptr4;
    ptr2->right = ptr5;
    ptr3->right = ptr7;
    connect(ptr1);
    return 0;
}
