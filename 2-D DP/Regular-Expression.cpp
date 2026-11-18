#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
/*
p is the pattern, s is the string to match
dp[i][l] match the first i characters of p to the first l characters of string s
base case dp[0][0] is true
dp[p.length][s.length] is the final answer

transition states:
dp[i][l]=dp[i-1][l-1] if the characters match
dp[i][l]=dp[i-1][l-1] if i is a '.'

if the character is *
dp[i][l]=dp[i-2][l]
 i j mean can the first i of the pattern match j strings
baaa ba*
dp[3][3] is true
dp[3][4] = dp [3][3]
dp[i][l]=dp[i][l-1]

*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=p.length();
        int m=s.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0]=true;
        for (int i=2; i<=n; i++) {
            if(p[i-1] == '*') {
                dp[i][0] = dp[i-2][0];
            }
        }

        for(int i=1; i<=n; i++){
            for(int l=1; l<=m; l++){
                if(p[i-1]=='*'){
                    dp[i][l]=dp[i-2][l];
                    if(p[i-2]==s[l-1]||p[i-2]=='.'){
                        dp[i][l]=dp[i][l-1]||dp[i][l];
                    }
                }

                else if(p[i-1]==s[l-1]||p[i-1]=='.'){
                    dp[i][l]=dp[i-1][l-1];
                }
            }
        }
        return dp[n][m];
    }
};

int main(){
    Solution sol;

    cout << boolalpha;
    cout << sol.isMatch("aa", "a") << endl;       // false
    cout << sol.isMatch("aa", "a*") << endl;      // true
    cout << sol.isMatch("ab", ".*") << endl;      // true
    cout << sol.isMatch("aab", "c*a*b") << endl;  // true
    cout << sol.isMatch("mississippi", "mis*is*p*.") << endl; // false



}