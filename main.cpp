#include <iostream>
#include <string>
#include "leetcode/daily/Solution.h"
#include "leetcode/algorithms/backtrack/BackTrack.h"
#include "sort/maopao/Maopao.h"
#include "sort/selection_sort/SelectionSort.h"
#include "sort/InsertionSort.h"
#include "sort/ShellSort.h"
#include "sort/HeapSort.h"
#include "sort/QuickSort.h"
#include "sort/MergeSort.h"

using namespace std;

int main() {
    MergeSort mergeSort;
    vector<int> nums({7,5,6,4});
    cout<< mergeSort.reversePairs(nums)<<endl;
    return 0;
}
