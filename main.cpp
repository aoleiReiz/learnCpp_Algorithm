#include <iostream>
#include <string>
#include "leetcode/daily/Solution.h"
#include "leetcode/algorithms/backtrack/BackTrack.h"
#include "sort/maopao/Maopao.h"
#include "sort/selection_sort/SelectionSort.h"

using namespace std;

int main() {
    SelectionSort selectionSort;
    vector<int> nums({3,2,1,5,6,4});
    cout<< selectionSort.findKthLargest(nums, 3)<<endl;
    return 0;
}
