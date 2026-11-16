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
// doesn't match, replace with character, dp[i-1][j-1]+1

class Solution {
public:
    int minDistance(string word1, string word2) {
        
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