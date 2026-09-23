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
    bool dfs(int parent, int curr, vector<bool> &visited, unordered_map<int, vector<int>> &c){
        visited[curr]=true;

        for(auto node : c[curr]){
            if(visited[node]&&node!=parent){
                return true;
            }
            if(node==parent){
                continue;
            }
            if(dfs(curr, node, visited, c)){
                return true;
            }
        }

        return false;

    };
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> c;
        vector<bool> visited(n, false);
        for(int i=0; i<edges.size(); i++){
            c[edges[i][0]].push_back(edges[i][1]);
            c[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        if(dfs(-1, 0, visited, c)||edges.size()!=n-1){
            return false;
        }
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
};




int main() {
    Solution sol;

    vector<vector<int>> edges1 = {
        {0,1},
        {0,2},
        {0,3},
        {1,4}
    };

    vector<vector<int>> edges2 = {
        {0,1},
        {1,2},
        {2,3},
        {1,3},
        {1,4}
    };

    cout << boolalpha;

    cout << sol.validTree(5, edges1) << endl; // expected true
    cout << sol.validTree(5, edges2) << endl; // expected false
}