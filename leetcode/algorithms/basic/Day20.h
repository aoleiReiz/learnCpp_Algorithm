//
// Created by 包傲磊 on 2023/2/2.
//

#ifndef LEARNCPP_ALGORITHM_DAY20_H
#define LEARNCPP_ALGORITHM_DAY20_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


class RandomizedSet {
private:
private:
    vector<int> nums;
    unordered_map<int, int> indices;
public:
    RandomizedSet() {
        srand((unsigned) time(NULL));
    }

    bool insert(int val) {
        if (indices.count(val)) {
            return false;
        }
        int index = nums.size();
        nums.emplace_back(val);
        indices[val] = index;
        return true;
    }

    bool remove(int val) {
        if (!indices.count(val)) {
            return false;
        }
        int index = indices[val];
        int last = nums.back();
        nums[index] = last;
        indices[last] = index;
        nums.pop_back();
        indices.erase(val);
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        data = vector(k, 0);
        head = tail = -1;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        tail = (tail + 1) % data.size();
        data[tail] = value;
        if (head == -1) {
            head = tail;
        }
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % data.size();
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == data.size();
    }

private:
    vector<int> data;
    int head;
    int tail;
    int size;
};

class MyCalendar {
private:
    vector<pair<int, int>> calender;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        for (auto pair: calender) {
            if (!(pair.second <= start || pair.first >= end)) {
                return false;
            }
        }
        calender.emplace_back(make_pair(start, end));
        return true;
    }
};

class Solution {
private:
    vector<int> data;
    vector<int> original;
public:
    Solution(vector<int> &nums) {
        data = nums;
        original.resize(nums.size());
        copy(nums.begin(), nums.end(), original.begin());
        srand((unsigned) time(NULL));
    }

    vector<int> reset() {
        copy(original.begin(), original.end(), data.begin());
        return data;
    }

    vector<int> shuffle() {
        random_shuffle(data.begin(), data.end());
        return data;
    }
};

bool isHappy(int n) {
    unordered_set<int> memo;
    while (n > 0) {
        if (memo.count(n) > 0) {
            return false;
        }
        memo.insert(n);
        int res = 0;
        while (n > 0) {
            int rem = n % 10;
            res += rem * rem;
            n = n / 10;
        }
        if (res == 1) {
            return true;
        }
        n = res;
    }
    return false;
}

int maxPoints(vector<vector<int>>& points) {
    int maxCount = 1;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double slope = points[j][0] - points[i][0] != 0 ? (points[j][1] - points[i][1]) * 1.0 / (points[j][0] - points[i][0]): INT_MAX;
            int pointCount = 2;
            vector<vector<int>>curLine;
            curLine.push_back(points[i]);
            curLine.push_back(points[j]);
            for (int k = j + 1; k < n; ++k) {
                double newSlope = points[k][0] - points[i][0] != 0 ? (points[k][1] - points[i][1]) * 1.0 / (points[k][0] - points[i][0]): INT_MAX;
                if (abs(slope - newSlope) < 0.00000001) {
                    curLine.push_back(points[k]);
                    pointCount++;
                }
            }
            maxCount = max(maxCount, pointCount);
        }
    }
    return maxCount;
}

#endif //LEARNCPP_ALGORITHM_DAY20_H
