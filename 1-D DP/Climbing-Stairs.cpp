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
        int prev2=1, prev1=2;
        for (int i = 2; i < n; i++)
        {
           int curr=prev1+prev2;
           prev2=prev1;
           prev1=curr;
        }
        return prev1;
    }
};

int main()
{
    Solution sol;
    cout<<sol.climbStairs(2)<<endl;
    cout<<sol.climbStairs(3)<<endl;
}