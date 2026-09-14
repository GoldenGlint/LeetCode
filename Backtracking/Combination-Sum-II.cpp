#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

void backtrack(int target, vector<int> &nums, vector<int> &current, vector<vector<int>> &ans, int sum, int start){
    if(sum>target){
        return;
    }
    else if(sum==target){
        ans.push_back(current);
    }
    else{
        for(int i=start; i<nums.size(); i++){
            if(i>start&&nums[i-1]==nums[i]){
                continue;
            }
            current.push_back(nums[i]);
            sum+=nums[i];
            if(sum>target){
                sum-=nums[i];
                current.pop_back();
                break;
            }
            backtrack(target, nums, current, ans, sum, i+1);
            sum-=nums[i];
            current.pop_back();
        }
    }


};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(target, candidates, current, ans, 0, 0);
        vector<vector<int>> nans;
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

int main() {
    Solution sol;

    vector<int> candidates={10,1,2,7,6,1,5};
    int target=8;
    
    vector<vector<int>> ans=sol.combinationSum2(candidates, target);
    cout<<"[";
    for(auto v:ans){
        cout<<"[";
        for(int i=0; i<v.size(); i++){
            if(i==v.size()-1){
                cout<<v[i];
            }
            else{
                cout<<v[i]<<",";
            }
        }
        cout<<"]";
    }
    cout<<"]";
}