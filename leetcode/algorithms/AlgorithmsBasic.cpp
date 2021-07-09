//
// Created by aolei.bao on 7/5/2021.
//

#include "AlgorithmsBasic.h"
#include <vector>
#include <algorithm>
using namespace std;


int AlgorithmsBasic::search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left <= right){
        int mid = (right - left)/ 2 + left;
        if (nums[mid] == target){
            return mid;
        }else if (nums[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

int AlgorithmsBasic::searchInsert(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right){
        int mid = (right - left)/ 2 + left;
        if (nums[mid] == target){
            return mid;
        }else if (nums[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

vector<int> AlgorithmsBasic::sortedSquares(vector<int> &nums) {
    vector<int>res;
    for(int &i : nums){
        res.push_back( i * i);
    }
    sort(res.begin(), res.end());
    return res;
}

void AlgorithmsBasic::rotate(vector<int> &nums, int k) {
    int n = nums.size();
    if (n <= 1){
        return;
    }
    k = k % n;
    reverseArray(nums, 0, n-1);
    reverseArray(nums, 0, k-1);
    reverseArray(nums, k, n-1);

}

void AlgorithmsBasic::reverseArray(vector<int> &arr, int left, int right) {
    while (left <= right){
        int temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;
        left ++;
        right --;
    }
}

void AlgorithmsBasic::moveZeroes(vector<int> &nums) {
    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0){
            nums[k++] = nums[i];
        }
    }
    while (k < nums.size()){
        nums[k++] = 0;
    }
}

vector<int> AlgorithmsBasic::twoSum(vector<int> &numbers, int target) {
    int i = 0, j = (int)numbers.size() - 1;
    while (i < j){
        int sum = numbers[i] + numbers[j];
        if (sum == target){
            return vector<int>({i+1, j+1});
        }else if (sum < target){
            i ++;
        }else{
            j --;
        }
    }
    return vector<int>();
}

void AlgorithmsBasic::reverseString(vector<char> &s) {
    if (s.size() <= 1){
        return;
    }
    int i = 0, j = s.size() - 1;
    while (i < j){
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i ++;
        j --;
    }
}

string AlgorithmsBasic::reverseWords(string s) {
    int n = (int)s.length();
    if (n <= 1){
        return s;
    }
    string ret = "";
    int i = 0, j = i + 1, k = 0;
    while (i < n){
        while (j < n && s[j] != ' '){
            j ++;
        }
        int left = i, right = j - 1;
        while (left <= right){
            ret += s[right--];
        }
        ret += ' ';
        i = j + 1;
        j = i + 1;
    }
    return ret.substr(0,n);
}

ListNode *AlgorithmsBasic::middleNode(ListNode *head) {
    int length = 0;
    ListNode *p = head;
    while (p != nullptr){
        length ++;
        p = p->next;
    }
    if (length == 1){
        return head;
    }
    int i = 0;
    p = head;
    while (i * 2 < length){
        p = p->next;
        i ++;
    }

    return p;
}

ListNode *AlgorithmsBasic::removeNthFromEnd(ListNode *head, int n) {
    ListNode * dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode * first = dummyHead;
    ListNode * second = dummyHead;
    int i = 0;
    while (i < n){
        first = first->next;
        i ++;
    }
    while (first->next != nullptr){
        first = first->next;
        second = second->next;
    }
    ListNode * deleteNode = second -> next;
    second->next = deleteNode->next;
    delete deleteNode;
    return dummyHead->next;
}

