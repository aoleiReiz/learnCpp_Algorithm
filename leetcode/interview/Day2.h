//
// Created by aolei.bao on 7/7/2021.
//

#ifndef LEARNCPP_ALGORITHM_DAY2_H
#define LEARNCPP_ALGORITHM_DAY2_H
#include <unordered_set>
#include <iostream>

using namespace std;


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


class Day2{
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = dummy;
        unordered_set<int>set;

        ListNode *p = head;
        while (p != nullptr){
            int val = p -> val;
            if (set.count(val) <= 0){
                set.insert(val);
                cur->next = p;
                cur = cur->next;
            }
            p = p->next;
        }
        cur->next = nullptr;
        return dummy->next;
    }
};

#endif //LEARNCPP_ALGORITHM_DAY2_H
