#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

void backtrack(vector<vector<bool>>& visited,
               vector<vector<char>>& board,
               bool& ans,
               int index,
               string word,
               int row,
               int col) {
    if(word[index]!=board[row][col]){
        return;
    }
    if (index == word.size()-1) {
        ans = true;
        return;
    }

    if (index >= word.length()) {
        return;
    }

    // down
    if (row + 1 < board.size() && !visited[row + 1][col]) {
        visited[row + 1][col] = true;
        backtrack(visited, board, ans, index+1, word, row + 1, col);
        visited[row + 1][col] = false;
        
    }

    // up
    if (row - 1 >= 0 && !visited[row - 1][col]) {
        visited[row - 1][col] = true;
        backtrack(visited, board, ans, index+1, word, row - 1, col);
        visited[row - 1][col] = false;
        
    }

    // left
    if (col - 1 >= 0 && !visited[row][col - 1]) {
        visited[row][col - 1] = true;
        backtrack(visited, board, ans, index+1, word, row, col - 1);
        visited[row][col - 1] = false;
    }

    // right
    if (col + 1 < board[0].size() && !visited[row][col + 1]) {
        visited[row][col + 1] = true;
        backtrack(visited, board, ans, index+1, word, row, col + 1);
        visited[row][col + 1] = false;
    }
}

class Solution {
public:
   bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    vector<vector<bool>> visited(
        rows,
        vector<bool>(cols, false)
    );

    bool ans = false;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {

            visited[row][col] = true;

            backtrack(
                visited,
                board,
                ans,
                0,
                word,
                row,
                col
            );

            visited[row][col] = false;

            if (ans) {
                return true;
            }
        }
    }

    return false;
}
};

int main() {
    Solution sol;
    vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    bool ans=sol.exist(board, "ABCCED");
    bool ans1=sol.exist(board, "SEE");
    bool ans2=sol.exist(board, "ABCB");
    cout<<ans<<endl;
    cout<<ans1<<endl;
    cout<<ans2<<endl;

}