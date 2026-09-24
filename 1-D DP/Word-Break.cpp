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
        vector<bool>dp(n, false);
        for(auto word:wordDict){
            int len=word.length();
            string temp=s.substr(0, len);
            if(temp==word){
                dp[len-1]=true;
            }
        }
        for(int i=0; i<n; i++){
            if(dp[i]){
                for(auto word:wordDict){
                    int len=word.length();
                    if(i+1+len>n){
                        continue;
                    }
                    else{
                        string temp=s.substr(i+1, len);
                        if(temp==word){
                            dp[i+len]=true;
                        }
                    }
                }
            }
            else{
                continue;
            }
        }
        return dp[n-1];
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