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

using namespace std;

int main() {
    QuickSort quickSort;
    vector<int> nums({3,2,3,1,2,4,5,5,6});
    quickSort.sortArray(nums);
    for (auto num: nums) {
        cout<< num << " ";
    }
    cout << endl;
    return 0;
}
