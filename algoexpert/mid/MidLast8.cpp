//
// Created by aolei.bao on 1/13/2023.
//

#include "MidLast8.h"

bool MidLast8::oneEdit(string stringOne, string stringTwo) {
    int oneLength = stringOne.length();
    int twoLength = stringTwo.length();
    if (oneLength - twoLength > 1 || oneLength - twoLength < -1){
        return false;
    }
    int indexOne = 0, indexTwo = 0;
    bool madeEdit = false;
    while (indexOne < oneLength && indexTwo < twoLength){
        if (stringOne[indexOne] != stringTwo[indexTwo]){
            if (madeEdit){
                return false;
            }
            madeEdit = true;
            if (oneLength > twoLength){
                indexOne ++;
            } else if (twoLength > oneLength){
                indexTwo ++;
            }else{
                indexOne ++;
                indexTwo ++;
            }
        }else{
            indexOne ++;
            indexTwo ++;
        }
    }
    return true;
}

bool MidLast8::symmetricalTree(BinaryTree *tree) {
    return symmetricalTreeHelper(tree, tree);
}

bool MidLast8::symmetricalTreeHelper(BinaryTree *tree1, BinaryTree *tree2) {
    if (tree1 == nullptr && tree2 == nullptr){
        return true;
    }
    else if(tree1 && tree2){
        return tree2->value == tree1->value && symmetricalTreeHelper(tree1->left, tree2->right) &&
                symmetricalTreeHelper(tree1->right, tree2->left);
    }
    return false;
}

LinkedList *MidLast8::mergingLinkedLists(LinkedList *linkedListOne, LinkedList *linkedListTwo) {
    unordered_set<LinkedList*>setOne;
    unordered_set<LinkedList*>setTwo;
    LinkedList *ptrOne = linkedListOne;
    LinkedList *ptrTwo = linkedListTwo;
    while (ptrOne || ptrTwo){
        if (ptrOne){
            setOne.insert(ptrOne);
        }
        if (ptrTwo) {
            setTwo.insert(ptrTwo);
        }
        if (ptrOne) {
            auto it1 = setTwo.find(ptrOne);
            if (it1 != setTwo.end()) {
                return *it1;
            }
        }
        if (ptrTwo){
            auto it2 = setOne.find(ptrTwo);
            if (it2 != setOne.end()){
                return *it2;
            }
        }
        if (ptrOne){
            ptrOne = ptrOne->next;
        }
        if (ptrTwo){
            ptrTwo = ptrTwo->next;
        }
    }
    return nullptr;
}

bool MidLast8::zeroSumSubarray(vector<int> nums) {
    vector<int> cumSum;
    int curSum = 0;
    for (auto num : nums){
        curSum +=num;
        cumSum.push_back(curSum);
        if (curSum == 0){
            return true;
        }
    }
    for (int i = 0; i < cumSum.size(); ++i) {
        for (int j = i+1; j < cumSum.size(); ++j) {
            if (cumSum[j] - cumSum[i] == 0){
                return true;
            }
        }
    }
    return false;
}

bool MidLast8::zeroSumHelper(vector<int> &nums, int startIndex, int curSum, vector<bool>visited, vector<int> path) {
    if (curSum == 0 && !path.empty()){
        return true;
    }
    for (int i = startIndex; i < nums.size(); ++i) {
        if (i > 0 and !visited[i - 1] && nums[i] == nums[i-1]){
            continue;
        }
        if (curSum + nums[i] > 0){
            continue;
        }
        visited[i] = true;
        path.push_back(nums[i]);
        if(zeroSumHelper(nums, i + 1, curSum + nums[i], visited, path)){
            return true;
        }
        visited[i] = false;
        path.pop_back();
    }
    return false;
}

bool MidLast8::zeroSumSubarray2(vector<int> nums) {
    unordered_set<int> sums({0});
    int currentSum = 0;
    for (auto num: nums) {
        currentSum += num;
        if (sums.find(currentSum) != sums.end()){
            return true;
        }
        sums.insert(currentSum);
    }
    return false;
}

bool MidLast8::twoColorable(vector<vector<int>> edges) {
    stack<int> stack;
    vector<int> colors(edges.size(), 0);
    colors[0] = 1;
    stack.push(0);
    while (!stack.empty()){
        int node = stack.top();
        stack.pop();
        for (int connection : edges[node]) {
            if (colors[connection] == 0){
                colors[connection] = colors[node] == 1 ? 2 : 1;
                stack.push(connection);
            } else if (colors[connection] == colors[node]){
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> MidLast8::stableInternships(vector<vector<int>> interns, vector<vector<int>> teams) {
   unordered_map<int, int> chosenInterns;
   stack<int> freeInterns;
    for (int i = 0; i < interns.size(); ++i) {
        freeInterns.push(i);
    }
    vector<int> currentInternChoices(interns.size(), 0);

    vector<unordered_map<int, int>> teamMaps;
    for (vector<int> & team: teams) {
        unordered_map<int, int> rank;
        for (int i = 0; i < teams.size(); ++i) {
           rank[team[i]] = i;
        }
        teamMaps.push_back(rank);
    }

    while (!freeInterns.empty()){
        int internNum = freeInterns.top();
        freeInterns.pop();

        vector<int> intern = interns[internNum];
        int teamPreference =  intern[currentInternChoices[internNum]];
        currentInternChoices[internNum] ++;

        if (chosenInterns.find(teamPreference) == chosenInterns.end()){
            chosenInterns[teamPreference] = internNum;
            continue;
        }

        int previousIntern = chosenInterns[teamPreference];
        int previousInternRank = teamMaps[teamPreference][previousIntern];
        int currentInternRank = teamMaps[teamPreference][internNum];

        if (currentInternRank < previousInternRank){
            freeInterns.push(previousIntern);
            chosenInterns[teamPreference] = internNum;
        }else{
            freeInterns.push(internNum);
        }
    }

    vector<vector<int>>matches;
    for(auto chosenIntern: chosenInterns){
        matches.push_back({chosenIntern.second, chosenIntern.first});
    }
    return matches;
}

