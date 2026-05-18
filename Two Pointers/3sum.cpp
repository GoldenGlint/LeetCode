#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            
            int index=i;
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int target=-nums[i];
            unordered_map<int, int> u;
            for(int l=index+1; l<nums.size(); l++){
                if(u.find(target-nums[l])!=u.end()){
                    sol.push_back({nums[i], nums[l], target-nums[l]});
                    while(l+1 < nums.size() && nums[l+1]==nums[l]) l++;
                }
                u[nums[l]]=l;

            }
        }

        return sol;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

}