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
        // Each bitset tracks which digits 1-9 have been seen
        int rows[9] = {}, cols[9] = {}, boxes[9] = {};

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                    continue;

                int val = board[r][c] - '1'; // 0-indexed digit
                int bit = 1 << val;
                int box = (r / 3) * 3 + (c / 3);

                if (rows[r] & bit)
                    return false;
                if (cols[c] & bit)
                    return false;
                if (boxes[box] & bit)
                    return false;

                rows[r] |= bit;
                cols[c] |= bit;
                boxes[box] |= bit;
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
}