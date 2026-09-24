#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int counter=0;
        for(int i=0; i<n; i++){
            dp[i][i]=true;
            counter++;
        }

        for(int len=2; len<=n; len++){
            for(int i=0; i<n-len+1; i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(len==2||dp[i+1][j-1]){
                        counter++;
                        dp[i][j]=true;
                    }
                }
            }
        }
        return counter;

    }
};

int main()
{
    Solution sol;
    string s1="abc";
    string s2="aaa";
    cout<<sol.countSubstrings(s1)<<endl;
    cout<<sol.countSubstrings(s2)<<endl;

    
}