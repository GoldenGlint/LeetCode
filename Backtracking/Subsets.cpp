#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

void backtrack(int start, vector<int> &nums, vector<int> &current, vector<vector<int>> &ans){
    ans.push_back(current);
    for(int i=start; i<nums.size(); i++){
        current.push_back(nums[i]);
        backtrack(i+1, nums, current, ans);
        current.pop_back();
    }

};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(0, nums, cur, ans);
        return ans;
        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    for (auto& subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i + 1 < subset.size()) cout << ", ";
        }
        cout << "]\n";
    }
}