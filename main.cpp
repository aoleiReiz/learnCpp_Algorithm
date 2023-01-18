#include <iostream>
#include "algoexpert/mid/MidLast8.h"
using namespace std;

int main() {
    MidLast8 m8;
    vector<int> nums({-5,-5,2,3,-2});
    cout << m8.zeroSumSubarray2(nums);
    return 0;
}
