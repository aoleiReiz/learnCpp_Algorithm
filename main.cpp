#include <iostream>

#include "leetcode/daily/Solution2.h"

using namespace std;

int main() {
    vector<string> names({"gta","gta(1)","gta","avalon"});
    Solution2 solution2;
    cout<<solution2.minimumDeletions("bbaaaaabb");
    return 0;
}
