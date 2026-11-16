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
        if (word2.size() > word1.size()) {
            swap(word1, word2);
        }

        int n = word1.size();
        int m = word2.size();

        vector<int> dp(m + 1);

        for (int j = 0; j <= m; j++) {
            dp[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            int diagonal = dp[0];
            dp[0] = i;

            for (int j = 1; j <= m; j++) {
                int above = dp[j];

                if (word1[i-1] == word2[j-1]) {
                    dp[j] = diagonal;
                } else {
                    dp[j] = 1 + min({
                        diagonal, // Replace
                        above,    // Delete
                        dp[j-1]   // Insert
                    });
                }

                diagonal = above;
            }
        }

        return dp[m];
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