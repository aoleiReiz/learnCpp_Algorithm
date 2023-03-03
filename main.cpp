#include <iostream>

#include "leetcode/daily/Solution2.h"

using namespace std;

int main() {
    vector<string> names({"gta","gta(1)","gta","avalon"});
    Solution2 solution2;
    for (string &s:solution2.getFolderNames(names)) {
        cout << s << endl;
    }
    return 0;
}
