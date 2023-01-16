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
#include "algoexpert/easy/EasyLast6.h"
#include "algoexpert/mid/Mid1to5.h"
#include "datastructure/UnionFind.h"
#include "leetcode/algorithms/basic/Day2.h"
#include "leetcode/algorithms/basic/ProgrammingDay3.h"
using namespace std;

int main() {
    ProgrammingDay3 s;
    vector<int > nums({0});
    vector<int> res = s.plusOne(nums);
    for(auto num : res){
        cout << num<<" ";
    }
    cout << endl;
    return 0;
}
