//
// Created by 包傲磊 on 2023/2/2.
//

#ifndef LEARNCPP_ALGORITHM_DAY20_H
#define LEARNCPP_ALGORITHM_DAY20_H
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class RandomizedSet {
private:
private:
    vector<int> nums;
    unordered_map<int, int> indices;
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
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
        int randomIndex = rand()%nums.size();
        return nums[randomIndex];
    }
};

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        data = vector(k,0);
        head = tail = -1;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()){
            return false;
        }
        tail = (tail + 1) % data.size();
        data[tail] = value;
        if(head == -1){
            head = tail;
        }
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()){
            return false;
        }
        head = (head + 1) % data.size();
        size --;
        return true;
    }

    int Front() {
        if (isEmpty()){
            return -1;
        }
        return data[head];
    }

    int Rear() {
        if (isEmpty()){
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
            if (!(pair.second <= start || pair.first>= end)){
                return false;
            }
        }
        calender.emplace_back(make_pair(start, end));
        return true;
    }
};

#endif //LEARNCPP_ALGORITHM_DAY20_H
