#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int minCostLast=0;
       int minCostFirst=0;
       for(int i=2; i<=cost.size(); i++){
            int currCost=min(minCostFirst+cost[i-1], minCostLast+cost[i-2]);
            minCostLast=minCostFirst;
            minCostFirst=currCost;
       }
       return minCostFirst;

    }
};

int main()
{
    Solution sol;
    vector<int> cost1= {10,15,20};
    vector<int> cost2= {1,100,1,1,1,100,1,1,100,1};
    cout<<sol.minCostClimbingStairs(cost1)<<endl;
    cout<<sol.minCostClimbingStairs(cost2)<<endl;
}