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
#include "sort/CountSort.h"
#include "sort/RadixSort.h"

using namespace std;

int main() {
    RadixSort rs;
    vector<int> nums({1,4,3,2});
    cout<<rs.arrayPairSum(nums) << endl;
    return 0;
}
