#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len=1;
        int index=0;
        if(s.length()==0){
            return "";
        }
        vector<vector<bool>>dp(s.length(), vector<bool>(s.length(), false));

        for(int i=0; i<s.length(); i++){
            dp[i][i]=true;
        }

        for(int i=2; i<=s.length(); i++){
            for(int l=0; l+i-1<s.length(); l++){
                int j=l+i-1;
                
                if(s[l]==s[j]&&(i==2||dp[l+1][j-1])){
                    dp[l][j]=true;
                    if(i>len){
                        len=i;
                        index=l;
                    }
                }
            }
        }

        return s.substr(index, len);
    }
};

int main()
{

    Solution sol;
    string s1="babad";
    string s2="cbbd";
    cout<<sol.longestPalindrome(s1)<<endl;
    cout<<sol.longestPalindrome(s2)<<endl;
    
}