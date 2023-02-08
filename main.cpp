#include <iostream>

#include "algoexpert/mid/MidLast8.h"

using namespace std;

int main() {
    MidLast8 midLast8;
    vector<vector<int>> interns({{0, 1, 2},
                                 {1, 0, 2},
                                 {1, 2, 0}});
    vector<vector<int>> teams({{2, 1, 0},
                               {1, 2, 0},
                               {0, 2, 1}});
    vector<int> r = midLast8.stableInternships(interns, teams);
    for(auto s: r){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
