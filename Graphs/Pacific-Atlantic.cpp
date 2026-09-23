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

    void dfs(vector<vector<bool>> &visited, pair<int, int> curr, vector<vector<int>> &heights, int &r, int &c){
        visited[curr.first][curr.second]=true;
        
        for(auto d: dir){
            int f=curr.first+d.first;
            int s=curr.second+d.second;
            if(f>=0 && f<r && s>=0 && s<c && !visited[f][s] && heights[f][s]>=heights[curr.first][curr.second]){
                dfs(visited, {f,s}, heights, r, c);
            }

        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>> ans;

        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));
        
        for(int l=0; l<c; l++){

            dfs(pacific, {0,l}, heights, r, c);
                
        }
        for(int i=0; i<r; i++){

            
            dfs(pacific, {i,0}, heights, r, c);
                
        }
        for(int l=0; l<c; l++){

            
            dfs(atlantic, {r-1,l}, heights, r, c);
                
        }
        for(int i=0; i<r; i++){

            
            dfs(atlantic, {i,c-1}, heights, r, c);
                
        }

        for(int i=0; i<r; i++){
            for(int l=0; l<c; l++){
                if(pacific[i][l]&&atlantic[i][l]){
                    ans.push_back({i,l});
                }
            }
        }
        return ans;
    }
};

void printVector(const vector<vector<int>>& v) {
    cout << "[";

    for (int i = 0; i < v.size(); i++) {
        cout << "[" << v[i][0] << "," << v[i][1] << "]";

        if (i != v.size() - 1) {
            cout << ",";
        }
    }

    cout << "]" << endl;
}

int main() {
 
    Solution sol;
    vector<vector<int>> grid = {
    {1, 2, 2, 3, 5},
    {3, 2, 3, 4, 4},
    {2, 4, 5, 3, 1},
    {6, 7, 1, 4, 5},
    {5, 1, 1, 2, 4}
};
    vector<vector<int>> ans=sol.pacificAtlantic(grid);
    printVector(ans);
    
}