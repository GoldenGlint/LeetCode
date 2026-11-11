#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//transitions are, if you are at dp[0][i], can either buy at i and dp[1][i+1]=dp[]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size()+1, INT_MIN));
        int n=prices.size();
        dp[0][0]=0;
        for(int i=0; i<prices.size(); i++){
            //case 0
            if(dp[0][i]!=INT_MIN){
                dp[0][i+1]=max(dp[0][i+1], dp[0][i]);
                dp[1][i+1] = max(dp[1][i+1], dp[0][i] - prices[i]);
            }
            if(dp[1][i]!=INT_MAX){
                dp[1][i+1] = max(dp[1][i+1], dp[1][i]);
                int next = min(i+2, n);
                dp[0][next] = max(dp[0][next], dp[1][i] + prices[i]);
            }
                        
        }

        return dp[0][n];
    }
};

int main(){
    Solution sol;

    vector<int> prices = {1, 2, 3, 0, 2};    
    vector<int> prices1 = {1};

    cout<<sol.maxProfit(prices)<<endl;
    cout<<sol.maxProfit(prices1)<<endl;
}