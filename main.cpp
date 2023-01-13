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

using namespace std;

int main() {
    UnionFind uf;
    uf.createSet(5);
    uf.createSet(10);
    cout << uf.find(5).value() <<endl;
    cout << uf.find(10).value() <<endl;
    uf.createUnion(5, 10);
    cout << uf.find(5).value() <<endl;
    cout << uf.find(10).value() <<endl;
    uf.createSet(20);
    cout << uf.find(20).value() << endl;
    uf.createUnion(20, 10);
    cout << uf.find(5).value() <<endl;
    cout << uf.find(10).value() <<endl;
    cout << uf.find(20).value() << endl;
    return 0;
}
