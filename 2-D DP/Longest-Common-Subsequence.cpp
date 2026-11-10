#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length();
        int l2=text2.length();
        vector<vector<int>> ans(l1+1, vector<int>(l2+1, 0));

        for(int i=1; i<=l1; i++){
            for(int l=1; l<=l2; l++){
                if(text1[i-1]==text2[l-1]){
                    
                    ans[i][l]=ans[i-1][l-1]+1;
                
                }
                else{
                    
                    ans[i][l]=max(ans[i-1][l], ans[i][l-1]);
                    
                }
                
            }
            
        }

        return ans[l1][l2];
        
    }
};

int main(){
    Solution sol;
    string text1 = "abc";
    string text2 = "edf";
    string text3 = "abcde";
    string text4 = "ace";
    cout<<sol.longestCommonSubsequence(text1, text2)<<endl;
    cout<<sol.longestCommonSubsequence(text3, text4)<<endl;
}