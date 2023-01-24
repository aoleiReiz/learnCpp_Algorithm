#include <iostream>

#include "leetcode/algorithms/basic/Day11.h"

using namespace std;

int main() {
    vector<int> manager({5,9,6,10,-1,8,9,1,9,3,4});
    vector<int> info({0,213,0,253,686,170,975,0,261,309,337});
    Day11 day11;
    cout << day11.numOfMinutes(11, 4, manager, info)<<endl;
    return 0;
}
