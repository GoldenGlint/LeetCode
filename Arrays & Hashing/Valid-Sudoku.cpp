#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> sq[9];

        for (int i = 0; i < board.size(); i++)
        {
            for (int l = 0; l < board[i].size(); l++)
            {
                if (board[i][l] != '.')
                {
                    int s;
                    if (i < 3 && l < 3)
                    {
                        s = 0;
                    }
                    else if (i < 3 && l < 6)
                    {
                        s = 1;
                    }
                    else if (i < 3 && l < 9)
                    {
                        s = 2;
                    }
                    else if (i < 6 && l < 3)
                    {
                        s = 3;
                    }
                    else if (i < 6 && l < 6)
                    {
                        s = 4;
                    }
                    else if (i < 6 && l < 9)
                    {
                        s = 5;
                    }
                    else if (i < 9 && l < 3)
                    {
                        s = 6;
                    }
                    else if (i < 9 && l < 6)
                    {
                        s = 7;
                    }
                    else if (i < 9 && l < 9)
                    {
                        s = 8;
                    }
                    char target = board[i][l];
                    if (rows[i].find(target) != rows[i].end() || cols[l].find(target) != cols[l].end() || sq[s].find(target) != sq[s].end())
                    {
                        return false;
                    }
                    rows[i].insert(target);
                    cols[l].insert(target);
                    sq[s].insert(target);
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
}