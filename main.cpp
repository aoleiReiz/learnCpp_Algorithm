#include <iostream>

#include "leetcode/interview/Day2.h"

using namespace  std;

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(2);
    ListNode *node6 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4 ->next = node5;
    node5 -> next = node6;
    Day2 day2;

    ListNode *r = day2.removeDuplicateNodes(node1);
    while (r != nullptr){
        cout << r -> val << " ";
        r = r -> next;
    }
    cout << endl;
    return 0;
}
