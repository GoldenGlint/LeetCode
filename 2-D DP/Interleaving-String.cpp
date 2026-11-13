#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length();
        int l2=s2.length();
        vector<vector<bool>> dp(l1+1, vector<bool>(l2+1, false));
        dp[0][0]=true;

        if(l1+l2!=s3.length()){
            return false;
        }

        for(int i=0; i<=l1; i++){
            for(int l=0; l<=l2; l++){
                if(i==0&&l==0){
                    continue;
                }
                if(i==0){
                    if(dp[i][l-1]&&s2[l-1]==s3[l-1]){
                        dp[i][l]=true;
                    }
                }
                if(l==0){
                    if(dp[i-1][l]&&s1[i-1]==s3[i-1]){
                        dp[i][l]=true;
                    }
                }
                if(i-1>=0){
                    if(dp[i-1][l]&&s1[i-1]==s3[i+l-1]){
                        dp[i][l]=true;
                    }
                }
                
                if(l-1>=0){
                    if(dp[i][l-1]&&s2[l-1]==s3[i+l-1]){
                        dp[i][l]=true;
                    }
                }
                
                
            }
        }

        /*for(int i=0; i<=l1; i++){
            for(int l=0; l<=l2; l++){
                cout<<dp[i][l]<<" ";
            }
            cout<<endl;
        }*/

        return dp[l1][l2];

    }
};

int main(){
    Solution sol;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout<<endl;
    cout<<sol.isInterleave(s1, s2, s3)<<endl;
    string s4 = "aabcc";
    string s5 = "dbbca";
    string s6 = "aadbbbaccc";
    cout<<endl;
    cout<<sol.isInterleave(s4, s5, s6)<<endl;
    string s7 = "";
    string s8 = "";
    string s9 = "";
    cout<<endl;
    cout<<sol.isInterleave(s7, s8, s9)<<endl;

}