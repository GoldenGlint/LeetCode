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
    bool dfs(unordered_map<int, vector<int>> &c, vector<int> &color, int curr, vector<int> &order){
        if(color[curr]==2){
            return false;
        }
        if(color[curr]==1){
            return true;
        }
        color[curr]=1;
        for(auto node : c[curr]){
            if(dfs(c, color, node, order)){
                return true;
            }
        }

        color[curr]=2;
        order.push_back(curr);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        
        vector<int> order;


        
        unordered_map<int, vector<int>> c;
        vector<int> color(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++){
            c[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0; i<numCourses; i++){
            if(dfs(c, color, i, order)){
                return {};
            }
        }

        reverse(order.begin(), order.end());

        return order;


    }
};


void printVector(const vector<int>& v) {
    cout << "[";

    for (int i = 0; i < v.size(); i++) {
        cout << v[i];

        if (i != v.size() - 1) {
            cout << ",";
        }
    }

    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> preq={{1,0}};
    vector<vector<int>> preq1={{1,0}, {2,0}, {3,1}, {3,2}};
    vector<vector<int>> preq3={};

    vector<int> ans=sol.findOrder(2,preq);
    vector<int> ans1=sol.findOrder(4,preq1);
    vector<int> ans2=sol.findOrder(3, preq3);

    printVector(ans);
    printVector(ans1);
    printVector(ans2);

}