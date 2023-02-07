#include <iostream>

#include "leetcode/daily/Solution2.h"

using namespace std;

int main() {
    Solution2 solution2;
    vector<string>names({"/a","/a/b","/c/d","/c/d/e","/c/f"});
    vector<string>res = solution2.removeSubfolders(names);
    for (auto s: res) {
        cout<<s <<endl;
    }
    return 0;
}
