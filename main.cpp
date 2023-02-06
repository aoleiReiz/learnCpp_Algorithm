#include <iostream>

#include "leetcode/daily/Solution2.h"

using namespace std;

int main() {
    Solution2 solution2;
    vector<string>names({"a","a","a","a","a","b","b","b","b","b","b"});
    vector<string>times({"04:48","23:53","06:36","07:45","12:16","00:52","10:59","17:16","00:36","01:26","22:42"});
    vector<string>res = solution2.alertNames(names, times);
    for (auto s: res) {
        cout<<s <<endl;
    }
    return 0;
}
