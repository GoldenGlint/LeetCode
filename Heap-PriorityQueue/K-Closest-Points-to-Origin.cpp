#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <math.h>

#include <cassert>
using namespace std;

class Solution {
public:
struct compare{
    bool operator()(pair<int, int>&a, pair<int, int> &b){
        return (pow(a.first, 2)+pow(a.second, 2))>(pow(b.first, 2)+pow(b.second, 2));
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for(int i=0; i<points.size(); i++){
            pq.push({points[i][0], points[i][1]});
        }
        vector<vector<int>> ans;
        for(int i=0; i<k; i++){
            pair<int, int> temp=pq.top();
            ans.push_back({temp.first, temp.second});
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points1 = {
        {1, 3},
        {-2, 2}
    };

    vector<vector<int>> result1 = sol.kClosest(points1, 1);

    for (auto& point : result1) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }

    cout << endl;

    vector<vector<int>> points2 = {
        {3, 3},
        {5, -1},
        {-2, 4}
    };

    vector<vector<int>> result2 = sol.kClosest(points2, 2);

    for (auto& point : result2) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }

    cout << endl;
}