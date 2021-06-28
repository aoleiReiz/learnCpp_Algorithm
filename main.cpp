#include <iostream>
#include <string>
#include "datastructure/hashmap/HashMapSolution.h"

using namespace  std;

int main() {
    HashMapSolution hashMapSolution;

    string s1 = "foo";
    string s2 = "bar";
    cout << hashMapSolution.isIsomorphic(s1, s2)<<endl;

    return 0;
}
