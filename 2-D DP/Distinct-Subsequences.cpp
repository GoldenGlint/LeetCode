#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//transition dp[i][l] i means first i characters from first string, l means number matching from string t
//dp[i][l]=dp[i-1][l]+dp[i-1][l-1]

class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int f=t.length();

        vector<vector<int>> dp(n+1, vector<int>(f+1, 0));
        dp[0][0]=1;
        for(int l=0; l<=n; l++){
            dp[l][0]=1;
        }
        for(int i=1; i<=n; i++){
            for(int l=1; l<=f; l++){
                long long res=dp[i-1][l];
                if(l-1<=f && s[i-1]==t[l-1]){
                    res+=dp[i-1][l-1];
                }
                dp[i][l]=(int)min((long long)INT_MAX, res);
            }
        }

        /*for(int i=0; i<=n; i++){
            for(int l=0; l<=f; l++){
                cout<<dp[i][l]<<" ";
            }
            cout<<endl;
        }*/

        return dp[n][f];
        
    }
};

int main(){
    Solution sol;

    string s = "rabbbit";
    string t = "rabbit";

    string s1 = "babgbag";
    string t1 = "bag";

    cout<<sol.numDistinct(s,t)<<endl;
    cout<<sol.numDistinct(s1, t1)<<endl;
    

    return 0;
}