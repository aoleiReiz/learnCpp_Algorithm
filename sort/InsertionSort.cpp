//
// Created by aolei.bao on 1/4/2023.
//

#include "InsertionSort.h"

vector<int> InsertionSort::sortArray(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int e = nums.at(i);
        int j = i - 1;
        for (; j >= 0 && nums.at(j) > e ; --j) {
            nums.at(j + 1) = nums.at(j);
        }
        nums.at(j + 1) = e;
    }

    return nums;
}

ListNode *InsertionSort::insertionSortList(ListNode *head) {
    ListNode * p = head;
    ListNode * dummyHead = new ListNode(-1);
    ListNode * cur = dummyHead;
    while (p != nullptr){
        while (cur->next && cur->next->val < p->val){
            cur = cur->next;
        }
        ListNode * temp = p->next;
        p -> next = cur->next;
        cur->next = p;
        cur = dummyHead;
        p = temp;
    }
    return dummyHead->next;
}
