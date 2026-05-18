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
        int n=nums.size();
        if (n < 3) return sol;
        for(int i=0; i<n-2; i++){
            if(i>0&&nums[i-1]==nums[i]){
                continue;
            }
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    sol.push_back({nums[i], nums[left], nums[right]});
                    while(left<right&&nums[left+1]==nums[left]){
                    left++;
                    }
                    while(left<right&&nums[right-1]==nums[right]){
                        right--;
                    }
                    left++;
                    right--;
                }   
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }


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