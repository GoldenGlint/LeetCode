#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (auto num : nums)
        {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &[num, count] : freq)
        {
            bucket[count].push_back(num);
        }
        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--)
        {
            for (int num : bucket[i])
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1, 1, 1, 2, 2, 3};
    vector<int> v2 = {1};
    vector<int> v3 = {
        1,
        2,
        1,
        2,
        1,
        2,
        3,
        1,
        3,
    };
    vector<int> a1 = sol.topKFrequent(v1, 2);
    vector<int> a2 = sol.topKFrequent(v2, 1);
    vector<int> a3 = sol.topKFrequent(v3, 2);

    for (auto a : a1)
    {
        cout << a << " ";
    }
    cout << endl;
    for (auto a : a2)
    {
        cout << a << " ";
    }
    cout << endl;
    for (auto a : a3)
    {
        cout << a << " ";
    }
    cout << endl;
}