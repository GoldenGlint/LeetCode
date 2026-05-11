#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <utility>

#include <cassert>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), count = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    count++;
                    queue<pair<int,int>> q;
                    q.push({r, c});
                    grid[r][c] = '0';
                    while (!q.empty()) {
                        auto [row, col] = q.front(); q.pop();
                        for (auto& d : dirs) {
                            int nr = row + d[0], nc = col + d[1];
                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                                grid[nr][nc] = '0';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid1 = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
};

vector<vector<char>> grid2 = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
};

cout<<sol.numIslands(grid1)<<endl;
cout<<sol.numIslands(grid2)<<endl;


}