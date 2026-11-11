#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        long n=coins.size();
        vector<int> dp(amount+1, 0);
        dp[0]=1;
        if(amount==0){
            return 1;
        }
        for(int i=1; i<=n; i++){
            for(int l=0; l<=amount; l++){
                if (l >= coins[i-1]) {
                    long long ways = (long long)dp[l]+dp[l-coins[i-1]];

                    dp[l] = (int)min(ways, (long long)INT_MAX);
                }
            }
        }
        
        
        return dp[amount];

    }
};

int main(){
    Solution sol;

    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout<<sol.change(amount, coins)<<endl;

}