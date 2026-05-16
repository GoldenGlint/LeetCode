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
        if (nums.empty())
            return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int m = 1;

        for (auto e : s)
        {
            if (s.find(e - 1) == s.end())
            {
                int counter = 1;
                while (s.find(e + counter) != s.end())
                {
                    counter++;
                }
                m = max(m, counter);
            }
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