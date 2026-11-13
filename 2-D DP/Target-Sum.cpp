#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//[i][l] where i is the amount of numbers you've used, l is the current value
//need to use all of them so answer is [nums.size][target], if it's 0, multiply by 2, I think it's mirrored
//transitions are dp[i][l]=dp[i-1][l+nums[i-1]]+dp[i-1][l-nums[i-1]]

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();

        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        
        int size=2*sum+1; //3, -3 -2 -1 0 1 2 3

        if(sum+target<0||sum+target>=size){
            return 0;
        }
        

        vector<int> dp(size, 0);

        dp[sum]=1;

        for(int i=1; i<=n; i++){
            vector<int> copy=dp;
            for(int l=0; l<size; l++){
                dp[l]=0;
                if(l+nums[i-1]<size){
                    dp[l]+=copy[l+nums[i-1]];
                }
                if(l-nums[i-1]>=0){
                    dp[l]+=copy[l-nums[i-1]];
                }
            }
            
            
        }
        

        

        return dp[sum+target];

        

    }
};

int main(){
    Solution sol;

    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    vector<int> nums1 = {1};
    int target1 = 1;

    cout<<sol.findTargetSumWays(nums, target)<<endl;
    cout<<sol.findTargetSumWays(nums1, target1)<<endl;

}