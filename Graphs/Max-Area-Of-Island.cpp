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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int k=grid.size();
        int n=grid[0].size();
        int maxArea=0;
        vector<vector<bool>> visited(k, vector<bool>(n, false));
        for(int i=0; i<grid.size(); i++){
            for(int l=0; l<grid[0].size(); l++){
                queue<pair<int, int>> q;
                int size=0;
                if(!visited[i][l]&&grid[i][l]==1){
                    q.push({i,l});
                    visited[i][l]=true;
                    size++;
                    vector<pair<int, int>> d={{0,1}, {1,0}, {0,-1}, {-1, 0}};
                    while(!q.empty()){
                        pair<int, int> t=q.front();
                        cout<<t.first<<" "<<t.second<<endl;
                        
                        
                        q.pop();
                        for(auto p: d){
                            pair<int, int> temp;
                            temp.first=t.first+p.first;
                            temp.second=t.second+p.second;
                            if(temp.first>=0 && temp.first<grid.size()&&temp.second>=0&&temp.second<grid[0].size()&&!visited[temp.first][temp.second]&&grid[temp.first][temp.second]==1){
                                q.push(temp);
                                size++;
                                visited[temp.first][temp.second]=true;
                            }
                        }
                    }
                }
                maxArea=max(maxArea, size);
            }
        }
        return maxArea;
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
    cout<<sol.maxAreaOfIsland(grid)<<endl;
    cout<<sol.maxAreaOfIsland(grid1)<<endl;

}