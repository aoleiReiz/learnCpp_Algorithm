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

using namespace std;

int main() {
    CountSort countSort;
    // arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
    vector<int> arr1({2,3,1,3,2,4,6,7,9,2,19});
    vector<int> arr2({2,1,4,3,9,6});
    countSort.relativeSortArray(arr1, arr2);
    for (auto num: arr1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
