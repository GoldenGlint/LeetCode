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

    bool dfs(int curr, vector<int> &colors, unordered_map<int, vector<int>> &c){
        if(colors[curr]==2){
            return false;
        }
        if(colors[curr]==1){
            return true;
        }

        if(colors[curr]==0){
            colors[curr]=1;
        }

        for(auto node : c[curr]){
            if(dfs(node, colors, c)){
                return true;
            }
        }

        colors[curr]=2;

        return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int>colors(numCourses, 0);

        unordered_map<int, vector<int>> c;

        for(int i=0; i<prerequisites.size(); i++){
            c[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0; i<numCourses; i++){
            if(dfs(i, colors, c)){
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution sol;

    vector<vector<int>> preq={{1,0}};
    vector<vector<int>> preq1={{1,0}, {0,1}};

    cout<<sol.canFinish(2, preq)<<endl;
    cout<<sol.canFinish(2, preq1)<<endl;
}