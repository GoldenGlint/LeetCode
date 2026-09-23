#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <utility>
#include <math.h>

#include <cassert>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir={{1,0}, {0,1}, {-1,0}, {0,-1}};

    void bfs(vector<vector<char>> &board, vector<vector<bool>> &visited, pair<int, int> start, int &r, int &c, char letter){

        if(visited[start.first][start.second]) return;
        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = true;
        
        
        while(!q.empty()){
            pair<int, int> t=q.front();
            q.pop();
            board[t.first][t.second] = letter;
            for(auto d : dir){
                pair<int, int> temp;
                temp.first=t.first+d.first;
                temp.second=t.second+d.second;
                if(temp.first>=0&&temp.first<r&&temp.second>=0&&temp.second<c&&!visited[temp.first][temp.second]&&board[temp.first][temp.second]=='O'){
                    q.push(temp);
                    visited[temp.first][temp.second] = true;
                }
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int r=board.size();
        int c=board[0].size();
        
        for(int i=0; i<r; i++){
            if(board[i][0]=='O'&&!visited[i][0]){

                bfs(board, visited, {i,0}, r, c, 'T');

            }
        }
        for(int i=0; i<r; i++){
            if(board[i][c-1]=='O'&&!visited[i][c-1]){

                bfs(board, visited, {i,c-1}, r, c, 'T');
                
            }
        }
        for(int l=0; l<c; l++){
                
            if(board[0][l]=='O'&&!visited[0][l]){

                bfs(board, visited, {0,l}, r, c, 'T');
                
            } 
                
        }
        for(int l=0; l<c; l++){
                
            if(board[r-1][l]=='O'&&!visited[r-1][l]){

                bfs(board, visited, {r-1,l}, r, c, 'T');
                
            } 
                
        }
        for(int i=0; i<r; i++){
            for(int l=0; l<c; l++){
                if(board[i][l]=='O'){
                    board[i][l]='X';
                }
                else if(board[i][l]=='T'){
                    board[i][l]='O';
                }
            }
        }
    }
};

void printBoard(const vector<vector<char>>& board) {
    cout << "[";

    for (int i = 0; i < board.size(); i++) {
        cout << "[";

        for (int j = 0; j < board[i].size(); j++) {
            cout << "\"" << board[i][j] << "\"";

            if (j != board[i].size() - 1) {
                cout << ",";
            }
        }

        cout << "]";

        if (i != board.size() - 1) {
            cout << ",";
        }
    }

    cout << "]" << endl;
}

int main() {
    Solution sol;
    vector<vector<char>> board = {
    {'X','X','X','X'},
    {'X','O','O','X'},
    {'X','X','O','X'},
    {'X','O','X','X'}
};
    sol.solve(board);
    printBoard(board);
   

}