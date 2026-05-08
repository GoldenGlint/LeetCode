#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        for (int i = 2; i < n; i++)
        {
            nums.push_back(nums[i - 2] + nums[i - 1]);
        }
        return nums[n - 1];
    }
};

int main()
{
    Solution sol;
    cout<<sol.climbStairs(2)<<endl;
    cout<<sol.climbStairs(3)<<endl;
}