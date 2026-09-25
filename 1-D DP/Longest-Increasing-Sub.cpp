#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
        }
        int ans=dp[0];
        for(int i=0; i<n; i++){
            ans=max(dp[i],ans);
        }
        return ans;
    }
};

int main()
{

    Solution sol;
    vector<int> v1={10,9,2,5,3,7,101,18};
    vector<int> v2={0,1,0,3,2,3};
    vector<int> v3={7,7,7,7,7,7,7};
    cout<<sol.lengthOfLIS(v1)<<endl;
    cout<<sol.lengthOfLIS(v2)<<endl;
    cout<<sol.lengthOfLIS(v3)<<endl;
    
    
}