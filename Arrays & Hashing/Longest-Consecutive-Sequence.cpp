#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int counter = 1;
        int m = 1;
        for (auto it = next(s.begin()); it != s.end(); it++)
        {
            int diff = *it - *prev(it);
            if (diff == 1)
            {
                counter++;
            }
            else
            {
                counter = 1;
            }
            m = max(counter, m);
        }

        return m;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {100, 4, 200, 1, 3, 2};
    vector<int> v2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> v3 = {1, 0, 1, 2};

    cout << sol.longestConsecutive(v1) << endl;
    cout << sol.longestConsecutive(v2) << endl;
    cout << sol.longestConsecutive(v3) << endl;
}