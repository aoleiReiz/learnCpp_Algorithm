#include <iostream>
#include <string>
#include "datastructure/array/ArraySolution.h"

using namespace  std;

int main() {
    ArraySolution algorithmsBasic;
    vector<vector<int>> mat = {{1,2},{3,4}};
    vector<vector<int>> res = algorithmsBasic.generate(5);
    for(vector<int> & row : res){
        for (int i : row){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
