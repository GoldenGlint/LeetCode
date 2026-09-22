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
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int notRotten=0;
        queue<pair<int, int>> q;
        for(int i=0; i<r; i++){
            for(int l=0; l<c; l++){
                if(grid[i][l]==2){
                    q.push({i, l});
                }
                else if(grid[i][l]==1){
                    notRotten++;
                }
            }
        }
        if(notRotten==0){
            return 0;
        }
        int time=0;
        vector<pair<int, int>> dir={{1,0}, {0,1}, {-1,0}, {0, -1}};
        while(!q.empty()){
            int s=q.size();
            for(int i=0; i<s; i++){
                pair<int, int> temp=q.front();
                //cout<<temp.first<<" "<<temp.second<<endl;
                q.pop();
                for(auto d: dir){
                    pair<int, int> t;
                    t.first=temp.first+d.first;
                    t.second=temp.second+d.second;
                    if(t.first>=0 && t.first<r && t.second>=0 && t.second<c && grid[t.first][t.second]==1){
                        grid[t.first][t.second]=2;
                        notRotten--;
                        q.push(t);
                        
                    }
                }
            }
            time++;
            if(notRotten==0){
                return time;
            }
        }
        return -1;
        
    }
};


int main() {
 
    Solution sol;
    vector<vector<int>> grid1={{2,1,1},{1,1,0},{0,1,1}};
    cout<<sol.orangesRotting(grid1)<<endl;
    vector<vector<int>> grid2={{2,1,1},{0,1,1},{1,0,1}};
    cout<<sol.orangesRotting(grid2)<<endl;
    vector<vector<int>> grid3={{0,2}};
    cout<<sol.orangesRotting(grid3)<<endl;

}