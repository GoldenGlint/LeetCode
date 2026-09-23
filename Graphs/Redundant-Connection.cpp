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
    
    bool dfs(int curr, int target, unordered_map<int, vector<int>> &adj, vector<bool> &visited){
        visited[curr]=true;
        if(curr==target){
            return true;
        }
        for(auto node:adj[curr]){
             
            if(!visited[node]){
                if(dfs(node, target, adj, visited)){
                    return true;
                }
            }
            
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<edges.size(); i++){
            vector<bool>visited(edges.size()+1, false);
            if(dfs(edges[i][0], edges[i][1], adj, visited)){
                return edges[i];
            }

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }
        return {-1,-1};
    }
};


int main() {

    Solution sol;
    vector<vector<int>> edges1={{1,2}, {1,3}, {2,3}};
    vector<int> ans1=sol.findRedundantConnection(edges1);
    cout<<ans1[0]<<" "<<ans1[1]<<endl;

    vector<vector<int>> edges2={{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    vector<int> ans2=sol.findRedundantConnection(edges2);
    cout<<ans2[0]<<" "<<ans2[1]<<endl;


}