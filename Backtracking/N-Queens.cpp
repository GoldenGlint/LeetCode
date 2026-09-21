#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

void backtrack(vector<string> &board, int row, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2, int &n, vector<vector<string>> &ans, int &counter){
    if(row>=n){
        ans.push_back(board);
    }
    for(int i=0; i<n; i++){
        if(!col[i]&&!diag1[row+i]&&!diag2[row-i+n-1]){
            board[row][i]='Q';
            col[i]=true;
            diag1[row+i]=true;
            diag2[row-i+n-1]=true;
            counter++;
            backtrack(board, row+1, col, diag1, diag2, n, ans, counter);

            board[row][i]='.';
            col[i]=false;
            diag1[row+i]=false;
            diag2[row-i+n-1]=false;
            counter--;
        }
    }
    //row-col+n-1
    //row+col
    
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<bool> col(n, false);
        vector<bool> diag1(2*n-1, false);
        vector<bool> diag2(2*n-1, false);
        int numQueens=0;
        int row=0;
        int counter=0;
        vector<vector<string>> ans;
        backtrack(board, 0, col, diag1, diag2, n, ans, counter);
        return ans;
    }
};

void printAnswer(const vector<vector<string>>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";

        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << '\n';
        }

        cout << '\n';
    }
}

int main() {

    Solution sol;

    int n=4;

    vector<vector<string>> ans=sol.solveNQueens(4);
    printAnswer(ans);

    
}