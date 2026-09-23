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
    
    int find(int node, vector<int> &parent){
        if(parent[node]!=node){
            parent[node]=find(parent[node], parent);
        }
        return parent[node];
    }
        
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       vector<int> parent(edges.size()+1);
        
        for(int i=0 ;i<parent.size(); i++){
            parent[i]=i;
        }

        for(auto edge: edges){
            int u=edge[0];
            int v=edge[1];

            int parentU=find(u, parent);
            int parentV=find(v, parent);

            if(parentU==parentV){
                return edge;
            }

            parent[parentU]=parentV;
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