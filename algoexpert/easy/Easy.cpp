//
// Created by aolei.bao on 12/30/2022.
//

#include "Easy.h"

vector<int> Easy::twoNumberSum(vector<int> array, int targetSum) {
    unordered_set<int> set;
    for (auto &i: array) {
        auto rem = targetSum - i;
        if (set.find(rem) != set.end()) {
            return vector<int>({i, rem});
        } else {
            set.insert(i);
        }
    }
    return vector<int>();
}

bool Easy::isValidSubsequence(vector<int> array, vector<int> sequence) {
    int arrIdx = 0;
    int seqIdx = 0;
    while (arrIdx < array.size() && seqIdx < sequence.size()) {
        if (array[arrIdx] == sequence[seqIdx]) {
            seqIdx++;
        }
        arrIdx ++;
    }
    return seqIdx == sequence.size();
}

vector<int> Easy::sortedSquaredArray(vector<int> array) {
    vector<int> res(array.size(), -1);
    int left = 0;
    int right = array.size() - 1;
    int idx = array.size() - 1;
    while (left <= right){
        int numLeft = array[left] * array[left];
        int numRight = array[right] * array[right];
        if (numLeft <= numRight){
            res[idx--] = numRight;
            right --;
        }else{
            res[idx--] = numLeft;
            left ++;
        }
    }
    return res;
}

string Easy::tournamentWinner(vector<vector<string>> competitions, vector<int> results) {
    unordered_map<string, int> map;
    int maxPoint = 0;
    string finalWinner = "";
    for (int i = 0; i < competitions.size(); ++i) {
        string  winner;
        if (results[i] == 0){
            winner = competitions[i][1];
        }else{
            winner = competitions[i][0];
        }
        map[winner] += 3;
        if (map[winner] > maxPoint){
            finalWinner = winner;
            maxPoint = map[winner];
        }
    }
    return finalWinner;
}

int Easy::nonConstructibleChange(vector<int> coins) {
    sort(coins.begin(), coins.end());
    int cur = 0;
    for (int coin: coins) {
        if (cur + 1 < coin){
            return cur + 1;
        }
        cur += coin;
    }
    return 0;
}
