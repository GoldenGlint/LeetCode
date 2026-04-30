#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int buy = prices[0];

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
            profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {7, 1, 5, 3, 6, 4};
    vector<int> v2 = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(v1) << endl;
    cout << sol.maxProfit(v2) << endl;
}
