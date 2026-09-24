#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n, 0);
        if(s[0]=='0'){
            return 0;
        }

        dp[0]=1;
        for(int i=1; i<s.length(); i++){
            if(s[i]!='0'){
                dp[i]+=dp[i-1];
            }
            int num=(s[i-1]-'0')*10+(s[i]-'0');
            if(num>=10&&num<=26){
                if(i==1){
                    dp[i]++;
                }
                else{
                    dp[i]+=dp[i-2];
                }
            }
        }
        return dp[s.length()-1];
    }
};

int main()
{
    Solution sol;
    string s1="12";
    string s2="226";
    string s3="06";
    string s4="10";
    cout<<sol.numDecodings(s1)<<endl;
    cout<<sol.numDecodings(s2)<<endl;
    cout<<sol.numDecodings(s3)<<endl;
    cout<<sol.numDecodings(s4)<<endl;
    
}