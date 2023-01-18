//
// Created by 包傲磊 on 2023/1/19.
//

#ifndef LEARNCPP_ALGORITHM_DAY6_H
#define LEARNCPP_ALGORITHM_DAY6_H

#include <iostream>
#include <vector>

using namespace std;

class Day6 {
public:

    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j) {
        int directions[][2] = {{1,  0},
                               {-1, 0},
                               {0,  1},
                               {0,  -1}};
        for (int k = 0; k < 4; ++k) {
            int new_i = i + directions[k][0];
            int new_j = j + directions[k][1];
            if (new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() &&
                grid[new_i][new_j] == '1' && !visited[new_i][new_j]) {
                visited[new_i][new_j] = true;
                bfs(grid, visited, new_i, new_j);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited;
        visited.reserve(m);
        for (int i = 0; i < m; ++i) {
            visited.push_back(vector<bool>(n, false));
        }
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    visited[i][j] = true;
                    bfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        for (int j = 0; j < isConnected[i].size(); ++j) {
            if (i != j && isConnected[i][j] > 0 && !visited[j]){
                visited[j] = true;
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]){
                visited[i] = true;
                dfs(isConnected, visited, i);
                count ++;
            }
        }
        return count;
    }
};

#endif //LEARNCPP_ALGORITHM_DAY6_H
