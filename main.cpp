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
using namespace std;

int main() {
    Solution s;
    string sentence1 = "v v i y PWG CQm", sentence2 = "S cfSD GsjbETXQ";
    cout<< s.areSentencesSimilar(sentence1, sentence2)<< endl;

    return 0;
}
