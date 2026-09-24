#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>> dp(n, {0,0});
        dp[0]={nums[0], nums[0]};
        for(int i=1; i<nums.size(); i++){
            dp[i].first=max({dp[i-1].first*nums[i], dp[i-1].second*nums[i], nums[i]});
            dp[i].second=min({dp[i-1].second*nums[i], dp[i-1].first*nums[i], nums[i]});
        }
        
        int ans=dp[0].first;
        for(int i=0; i<dp.size(); i++){
            ans=max(ans, dp[i].first);
        }
        
        
        return ans;

    }
};

int main()
{

    Solution sol;
    vector<int> v1={2,3,-2,4};
    vector<int> v2={-2,0,-1};
    vector<int> v3={-2,3,-4};
    cout<<sol.maxProduct(v1)<<endl;
    cout<<sol.maxProduct(v2)<<endl;
    cout<<sol.maxProduct(v3)<<endl;
    
    
}