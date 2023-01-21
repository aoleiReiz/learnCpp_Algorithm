//
// Created by 包傲磊 on 2023/1/21.
//

#ifndef LEARNCPP_ALGORITHM_DAY8_H
#define LEARNCPP_ALGORITHM_DAY8_H

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    const int directions[][2] = {{1,  0},
                                 {-1, 0},
                                 {0,  1},
                                 {0,  -1},
                                 {1,  1},
                                 {1,  -1},
                                 {-1, 1},
                                 {-1, -1}
    };
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
        return -1;
    }
    vector<vector<bool>> seen;
    for (int i = 0; i < m; ++i) {
        vector<bool> row(n, false);
        seen.push_back(row);
    }
    queue<vector<int>> q;
    q.push(vector<int>({0, 0}));
    seen[0][0] = true;
    int step = 0;
    while (!q.empty()) {
        int size = q.size();
        step++;
        while (size > 0) {
            vector<int> pos = q.front();
            if (pos[0] == m - 1 && pos[1] == n - 1) {
                return step;
            }
            q.pop();
            for (int i = 0; i < 8; ++i) {
                int new_x = pos[0] + directions[i][0];
                int new_y = pos[1] + directions[i][1];
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 0 &&
                    !seen[new_x][new_y]) {
                    seen[new_x][new_y] = true;
                    q.push(vector<int>({new_x, new_y}));
                }
            }
            size--;
        }
    }
    return -1;
}


void solve(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();
    const int directions[][2] = {{1,  0},
                                 {-1, 0},
                                 {0,  1},
                                 {0,  -1}};
    vector<vector<bool>> seen;
    vector<vector<int>> needChangPos;
    for (int i = 0; i < m; ++i) {
        vector<bool> row(n, false);
        seen.push_back(row);
    }
    queue<vector<int>> q;
    for (int i = 0; i < m; ++i) {
        if (!seen[i][0] && board[i][0] == 'O') {
            seen[i][0] = true;
            q.push(vector<int>({i, 0}));
        }
        if (!seen[i][n - 1] && board[i][n - 1] == 'O') {
            seen[i][n - 1] = true;
            q.push(vector<int>({i, n - 1}));
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!seen[0][i] && board[0][i] == 'O') {
            seen[0][i] = true;
            q.push(vector<int>({0, i}));
        }
        if (!seen[m - 1][i] && board[m - 1][i] == 'O') {
            seen[m - 1][i] = true;
            q.push(vector<int>({m - 1, i}));
        }
    }
    while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
            vector<int> pos = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = pos[0] + directions[i][0];
                int y = pos[1] + directions[i][1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O' && !seen[x][y]) {
                    seen[x][y] = true;
                    q.push(vector<int>({x, y}));
                }
            }
            size--;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O' && !seen[i][j]) {
                board[i][j] = 'X';
            }
        }
    }
}

void allPathsSourceTargetHelper(vector<vector<int>> &graph, vector<int> curPath, int node, vector<vector<int>> &ans, vector<bool>& seen) {
    if (node == graph.size() - 1) {
        vector<int> cur({0});
        for (auto n: curPath) {
            cur.push_back(n);
        }
        ans.push_back(cur);
        return;
    }
    for (int connectionNode: graph[node]) {
        if (seen[connectionNode]){
            continue;
        }
        seen[connectionNode] = true;
        curPath.push_back(connectionNode);
        allPathsSourceTargetHelper(graph, curPath, connectionNode, ans, seen);
        seen[connectionNode] = false;
        curPath.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> ans;
    vector<bool> seen(graph.size(), false);
    allPathsSourceTargetHelper(graph, vector<int>(), 0, ans , seen);
    return ans;
}

#endif //LEARNCPP_ALGORITHM_DAY8_H
