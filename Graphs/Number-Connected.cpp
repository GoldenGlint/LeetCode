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
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<bool> visited(n, false);

        unordered_map<int, vector<int>> adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i]=true;
                ans++;
                while(!q.empty()){
                    int curr=q.front();
                    q.pop();
                    for(auto node : adj[curr]){
                        if(!visited[node]){
                            q.push(node);
                            visited[node]=true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> edges1 = {
    {{0,1}, {1,2}, {3,4}}
};
    vector<vector<int>> edges2={
        {{0,1}, {1,2}, {2,3}, {3,4}}
    };
    int a1=sol.countComponents(5, edges1);
    int a2=sol.countComponents(5, edges2);
    
    cout<<a1<<endl;
    cout<<a2<<endl;

}