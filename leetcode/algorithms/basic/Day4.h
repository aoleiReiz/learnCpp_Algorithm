//
// Created by 包傲磊 on 2023/1/17.
//

#ifndef LEARNCPP_ALGORITHM_DAY4_H
#define LEARNCPP_ALGORITHM_DAY4_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Day4 {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> sVec;
        vector<char> tVec;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (*it == '#') {
                if (!sVec.empty()) {
                    sVec.pop_back();
                }
            } else {
                sVec.push_back(*it);
            }
        }
        for (auto it = t.begin(); it != t.end(); ++it) {
            if (*it == '#') {
                if (!tVec.empty()) {
                    tVec.pop_back();
                }
            } else {
                tVec.push_back(*it);
            }
        }
        auto itSvec = sVec.begin();
        auto itTvec = tVec.begin();
        while (itSvec != sVec.end() && itTvec != tVec.end()) {
            if (*itTvec != *itSvec) {
                return false;
            }
            ++itSvec;
            ++itTvec;
        }
        return itTvec == tVec.end() && itSvec == sVec.end();
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        auto iterFirst = firstList.begin();
        auto iterSecond = secondList.begin();
        vector<vector<int>> intervalSections;
        while (iterFirst != firstList.end() && iterSecond != secondList.end()) {
            int intersectionLeft = max(*(iterFirst->begin()), *(iterSecond->begin()));
            int intersectionRight = min(*(iterFirst->begin() + 1), *(iterSecond->begin() + 1));
            if (intersectionLeft <= intersectionRight) {
                intervalSections.push_back(vector<int>({intersectionLeft, intersectionRight}));
            }
            if (*(iterFirst->begin() + 1) < *(iterSecond->begin() + 1)) {
                iterFirst++;
            } else if (*(iterFirst->begin() + 1) == *(iterSecond->begin() + 1)) {
                iterFirst++;
                iterSecond++;
            }else{
                iterSecond ++;
            }
        }
        return intervalSections;
    }

    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() -1, ans = 0;
        while (l < r){
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] <= height[r]){
                ++l;
            }else{
                --r;
            }
        }
        return ans;
    }
};

#endif //LEARNCPP_ALGORITHM_DAY4_H
