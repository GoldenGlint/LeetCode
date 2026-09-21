#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

bool checkValid(){

}

void backtrack(vector<vector<bool>> &visited, vector<string> &board, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2, int &n){
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
    }
};

int main() {
    

    
}