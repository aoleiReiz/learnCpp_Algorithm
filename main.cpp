#include <iostream>

#include "leetcode/daily/Solution.h"

using namespace  std;

int main() {
    Solution solution;
    vector<vector<string>>orders;
    vector<string> order1 = {"David","3","Ceviche"};
    orders.push_back(order1);
    vector<string> order2 = {"Corina","10","Beef Burrito"};
    orders.push_back(order2);
    vector<string> order3 = {"David","3","Fried Chicken"};
    orders.push_back(order3);
    vector<string> order4 = {"Carla","5","Water"};
    orders.push_back(order4);
    vector<string> order5 = {"Carla","5","Ceviche"};
    orders.push_back(order5);
    vector<string> order6 = {"Rous","3","Ceviche"};
    orders.push_back(order6);

    vector<vector<string>> tables = solution.displayTable(orders);
    for(vector<string> & row: tables){
        for(string &i : row){
            cout<< i << "--";
        }
        cout << endl;
    }

    return 0;
}
