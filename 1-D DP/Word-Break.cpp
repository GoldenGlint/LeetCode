#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool>dp(n+1, false);
        dp[0]=true;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(dp[j]&&words.count(s.substr(j, i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    string s1="leetcode";
    vector<string> v1={"leet", "code"};
    string s2="applepenapple";
    vector<string> v2={"apple", "pen"};
    string s3="catsandog";
    vector<string> v3={"cats", "dog", "sand", "and", "cat"};
    cout<<sol.wordBreak(s1, v1)<<endl;
    cout<<sol.wordBreak(s2, v2)<<endl;
    cout<<sol.wordBreak(s3, v3)<<endl;

    
}