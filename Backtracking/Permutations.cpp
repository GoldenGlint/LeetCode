#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

void backtrack(int start, vector<int> &nums, vector<vector<int>> &ans){
    if(start==nums.size()){
        ans.push_back(nums);
    }
    for(int i=start; i<nums.size(); i++){
        swap(nums[start], nums[i]);
        backtrack(start+1, nums, ans);
        swap(nums[start], nums[i]);

    }

};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        backtrack(0, nums, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    for (auto& v : result) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i + 1 < v.size()) cout << ", ";
        }
        cout << "]\n";
    }
}