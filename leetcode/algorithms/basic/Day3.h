//
// Created by aolei.bao on 1/16/2023.
//

#ifndef LEARNCPP_ALGORITHM_DAY3_H
#define LEARNCPP_ALGORITHM_DAY3_H

#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Day3 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *prev = dummyHead;
        ListNode *curr = prev->next;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                int val = curr->val;
                while (curr && curr->val == val) {
                    curr = curr->next;
                }
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummyHead->next;
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            if (nums[i] > 0){
                break;
            }
            vector<vector<int>>twoSumRes = twoSum(nums, i + 1, -nums[i]);
            for (vector<int> r: twoSumRes) {
                res.push_back(vector<int>({nums[i], r[0], r[1] }));

            }
        }
        return res;
    }

    vector<vector<int>> twoSum(vector<int> &nums, int startIndex, int target) {
        vector<vector<int>> ret;
        int left = startIndex;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                ret.push_back(vector<int>({nums[left], nums[right]}));
                int currLeft = nums[left];
                while ( left < right && nums[left] == currLeft)
                    left ++;
                int currRight = nums[right];
                while (right > left && nums[right] == currRight)
                    right --;
            }
        }
        return ret;
    }
};


#endif //LEARNCPP_ALGORITHM_DAY3_H
