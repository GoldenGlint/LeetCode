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
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int island=0;
        for(int i=0; i<grid.size(); i++){
            for(int l=0; l<grid[0].size(); l++){
                if(grid[i][l]=='1'&&visited[i][l]==0){
                    island++;
                    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
                    queue <pair<int, int>> q;
                    q.push({i, l});
                    visited[i][l]=true;
                    while(!q.empty()){
                        auto [row, col] = q.front();
                        q.pop();
                        for(auto [dr, dc]: dirs){
                           int nrow=row+dr;
                           int ncol=col+dc;
                            if(nrow>=0&&ncol>=0&&nrow<grid.size()&&ncol<grid[0].size()){
                                if(grid[nrow][ncol]=='1'&&visited[nrow][ncol]==false){
                                    q.push(make_pair(nrow, ncol));
                                    visited[nrow][ncol]=true;
                                }
                            }
                        }
                    }
                }
                visited[i][l]=true;
                
            }
        }
        return island;
        
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