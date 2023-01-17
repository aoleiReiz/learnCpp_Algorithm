#include <iostream>
#include "algoexpert/mid/MidLast8.h"
using namespace std;

int main() {
    MidLast8 m8;
    LinkedList *p1 = new LinkedList(2);
    LinkedList *p2 = new LinkedList(3);
    LinkedList *p3 = new LinkedList(1);
    LinkedList *p4 = new LinkedList(4);
    LinkedList *p5 = new LinkedList(8);
    LinkedList *p6 = new LinkedList(7);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p5->next = p6;
    p6->next = p3;
    LinkedList *head = m8.mergingLinkedLists(p1, p5);
    while (head){
        cout << head->value << " -> ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
