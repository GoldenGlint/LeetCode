#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <utility>
#include <math.h>

#include <cassert>
using namespace std;




class Solution {
public:
    int ans=0;
    vector<pair<int, int>> dir={{1,0}, {0,1}, {-1,0}, {0,-1}};
    void dfs(int &area, vector<vector<bool>> &visited, pair<int, int> curr, int r, int c, vector<vector<int>>& grid){
        ans=max(ans, area);
        visited[curr.first][curr.second]=true;
        for(auto d: dir){
            pair<int, int> temp=curr;
            temp.first=curr.first+d.first;
            temp.second=curr.second+d.second;
            if(temp.first>=0&&temp.first<r&&temp.second>=0&&temp.second<c&&!visited[temp.first][temp.second]&&grid[temp.first][temp.second]==1){
                area++;
                dfs(area, visited, temp, r, c, grid);
            }
        }
    };
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for(int i=0; i<r; i++){
            for(int l=0; l<c; l++){
                if(!visited[i][l]&&grid[i][l]==1){
                    int a=1;
                    dfs(a, visited, {i,l}, r, c, grid);
                }
            }
        }

        return ans;

    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
};
    vector<vector<int>> grid1={
        {1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}
    };
    //cout<<sol.maxAreaOfIsland(grid)<<endl;
    cout<<sol.maxAreaOfIsland(grid1)<<endl;

}