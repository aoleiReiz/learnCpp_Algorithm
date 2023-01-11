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

using namespace std;

int main() {
    EasyLast6 e;
    vector<string> words({"dog", "god"});
    vector<vector<string>> res = e.semordnilap(words);
    for (auto & vec: res) {
        for (string s: vec) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
