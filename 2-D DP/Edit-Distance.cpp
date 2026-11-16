#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


//transition states
//dp[i][j] transform the first i letters into first j letters
//dp[i][0] add i because delete i times
//dp[0][j] add j because insert j letters
//matches, do nothing
// doesn't match, 
//1. replace with character, dp[i-1][j-1]+1
//2. delete character dp[i-1][j]+1
//3. add character dp[i][j-1]+1



class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int s=word2.length();
        vector<vector<int>> dp(n+1, vector<int>(s+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0]=i;
        }
        for(int l=0; l<=s; l++){
            dp[0][l]=l;
        }
        for(int i=1; i<=n; i++){
            for(int l=1; l<=s; l++){
                int result=min({dp[i-1][l-1], dp[i-1][l], dp[i][l-1]});
                if(word1[i-1]==word2[l-1]){
                    dp[i][l]=dp[i-1][l-1];
                }
                else{
                    dp[i][l]=result+1;
                }
            }
        }
        return dp[n][s];
    }
};

int main(){
    Solution sol;

    string word1 = "horse";
    string word2 = "ros";

    string word3 = "intention";
    string word4 = "execution";

    cout<<sol.minDistance(word1,word2)<<endl;
    cout<<sol.minDistance(word3, word4)<<endl;
    

    return 0;
}