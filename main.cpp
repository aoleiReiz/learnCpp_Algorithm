#include <iostream>
#include <string>
#include "leetcode/daily/Solution.h"
#include "leetcode/algorithms/backtrack/BackTrack.h"
#include "sort/maopao/Maopao.h"
#include "sort/selection_sort/SelectionSort.h"
#include "sort/InsertionSort.h"

using namespace std;

int main() {
    InsertionSort insertionSort;
    ListNode *l1 = new ListNode(4);
    ListNode *l2 = new ListNode(2);
    ListNode *l3= new ListNode(1);
    ListNode *l4 = new ListNode(3);
    l1 -> next = l2;
    l2-> next = l3;
    l3 -> next = l4;
    ListNode * head = insertionSort.insertionSortList(l1);
    while ( head){
        cout<< head->val << "->";
        head = head->next;
    }
    cout << endl;
    return 0;
}
