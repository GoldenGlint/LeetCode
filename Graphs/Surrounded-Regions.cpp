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

    void bfs(vector<vector<char>> &board, vector<vector<bool>> &visited, pair<int, int> start, int &r, int &c){
        vector<pair<int, int>> indexes;
        bool captured=false;
        if(visited[start.first][start.second]) return;
        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = true;
        
        while(!q.empty()){
            pair<int, int> t=q.front();
            q.pop();
            indexes.push_back(t);
            if(t.first==0||t.first==r-1||t.second==0||t.second==c-1){
                captured=true;
            }
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

        if(!captured){
            for(auto pair: indexes){
                board[pair.first][pair.second]='X';
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int r=board.size();
        int c=board[0].size();
        for(int i=0; i<r; i++){
            for(int l=0; l<c; l++){
                
                if(board[i][l]=='O'&&!visited[i][l]){
                    bfs(board, visited, {i,l}, r, c);
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