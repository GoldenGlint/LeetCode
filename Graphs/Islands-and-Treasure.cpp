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
        vector<pair<int, int>> dir={{1,0}, {0,1}, {-1,0}, {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;
        int r=grid.size();
        int c=grid[0].size();
        
        int counter=0;
        for(int i=0; i<r; i++){
            for(int l=0; l<c; l++){
                if(grid[i][l]==0){
                    q.push({i,l});
                }
            }
        }
        while(!q.empty()){
            int s=q.size();
            for(int i=0; i<s; i++){
            pair<int, int> temp=q.front();
                q.pop();
                if(grid[temp.first][temp.second]==INT_MAX){
                    grid[temp.first][temp.second]=counter;
                }
                for(auto d: dir){
                    pair<int, int> t;
                    t.first=temp.first+d.first;
                    t.second=temp.second+d.second;
                    if(t.first>=0&&t.first<r&&t.second>=0&&t.second<c&&grid[t.first][t.second]==INT_MAX){
                        q.push(t);
                        grid[t.first][t.second]=counter+1;
                        
                    }
                }
            }
            counter++;
        }
    }
};

void printGrid(vector<vector<int>> grid){
    for(int i=0; i<grid.size(); i++){
        for(int l=0; l<grid[0].size(); l++){
            cout<<grid[i][l]<<",";
        }
        cout<<endl;
        
    }
}

int main() {
    Solution sol;
    vector<vector<int>> grid={{2147483647,-1,0,2147483647},
  {2147483647,2147483647,2147483647,-1},
  {2147483647,-1,2147483647,-1},
  {0,-1,2147483647,2147483647}};
  vector<vector<int>> grid1 = {
    {0, -1},
    {2147483647, 2147483647}
};
  sol.islandsAndTreasure(grid);
  printGrid(grid);

  sol.islandsAndTreasure(grid1);
  printGrid(grid1);


}