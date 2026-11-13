#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;



class Solution {
public:
    int rows, cols;
    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        dp[i][j]=1;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int x = i + dr[k];
            int y = j + dc[k];

            // Check bounds and strictly increasing
            if (x >= 0 && x < rows &&
                y >= 0 && y < cols &&
                matrix[x][y] > matrix[i][j]) {

                dp[i][j] = max(dp[i][j], 1 + dfs(x, y, matrix));
            }
        }

        return dp[i][j];

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();

        dp = vector<vector<int>>(rows, vector<int>(cols, 0));

        int ans = 0;

        // Start DFS from every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;


    vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    vector<vector<int>> matrix1 = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
    vector<vector<int>> matrix2 = {{1}};




    cout<<sol.longestIncreasingPath(matrix)<<endl;
    cout<<sol.longestIncreasingPath(matrix1)<<endl;
    cout<<sol.longestIncreasingPath(matrix2)<<endl;

}