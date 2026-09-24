#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, INT_MAX);
        if(amount==0){
            return 0;
        }
        
        for(int i=0; i<dp.size(); i++){
            for(int l=0; l<coins.size(); l++){
                if(i==coins[l]){
                    dp[i]=1;
                }
                else if(i-coins[l]>=1){
                    if(dp[i-coins[l]]==INT_MAX){
                        continue;
                    }
                    else{
                        dp[i]=min(dp[i], dp[i-coins[l]]+1);
                    }
                }
                
            }
        }
        
        return dp[amount]==INT_MAX? -1 : dp[amount];
    }
};

int main()
{
    Solution sol;
    vector<int> v1={1,2,5};
    vector<int> v2={2};
    vector<int> v3={1};
    cout<<sol.coinChange(v1,11)<<endl;
    cout<<sol.coinChange(v2, 3)<<endl;
    cout<<sol.coinChange(v3, 0)<<endl;
}