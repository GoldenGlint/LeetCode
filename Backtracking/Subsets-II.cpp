#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

void backtrack(vector<vector<int>> &ans, int start, vector<int> &nums, vector<int> &curr){
    ans.push_back(curr);

    for(int i=start; i<nums.size(); i++){
        if(i>start&&nums[i]==nums[i-1]){
            continue;
        }
        curr.push_back(nums[i]);
        backtrack(ans, i+1, nums, curr);
        curr.pop_back();
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, 0, nums, curr);
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,2,2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);
    cout<<"[";
    for (auto& subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i + 1 < subset.size()) cout << ", ";
        }
        cout << "], ";
    }
    cout<<"]";
}