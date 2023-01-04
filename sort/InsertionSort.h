//
// Created by aolei.bao on 1/4/2023.
//

#ifndef LEARNCPP_ALGORITHM_INSERTIONSORT_H
#define LEARNCPP_ALGORITHM_INSERTIONSORT_H
#include <vector>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



class InsertionSort {
public:
    vector<int> sortArray(vector<int>& nums);
    ListNode* insertionSortList(ListNode* head);
};


#endif //LEARNCPP_ALGORITHM_INSERTIONSORT_H
