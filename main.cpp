#include <iostream>

#include "leetcode/algorithms/basic/Day19.h"

using namespace std;

int main() {
    MyLinkedList li;
    li.addAtHead(0);
    li.printList();
    li.addAtIndex(1, 4);
    li.printList();
    li.addAtTail(8);
    li.printList();
    li.addAtHead(5);
    li.printList();
    li.addAtIndex(4, 3);
    li.printList();
    li.addAtTail(0);
    li.printList();
    li.addAtTail(5);
    li.printList();
    li.addAtIndex(6, 3);
    li.printList();
    li.deleteAtIndex(7);
    li.printList();
    li.deleteAtIndex(5);
    li.printList();
    li.addAtTail(4);
    li.printList();
    cout << li.get(1)<<endl;
    li.deleteAtIndex(0);
    cout << li.get(0)<<endl;

    return 0;
}
