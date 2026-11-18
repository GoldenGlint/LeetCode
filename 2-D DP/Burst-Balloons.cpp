#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for(int len=1; len<=n; len++){
            for(int i=1; i+len-1<=n; i++){
                int j=i+len-1;
                for(int k=i; k<=j; k++){
                    int coins=dp[i][k-1]+dp[k+1][j]+nums[k]*nums[i-1]*nums[j+1];
                    dp[i][j]=max(dp[i][j], coins);
                }
            }
        }

        return dp[1][n];
    }
};

int main(){
    Solution sol;

    vector<int> nums = {3, 1, 5, 8};
    vector<int> nums1 = {1, 5};
    cout<<sol.maxCoins(nums)<<endl;
    cout<<sol.maxCoins(nums1)<<endl;


}