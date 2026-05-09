#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost;
        if(cost.size()<=1){
            return 0;
        }
        for(int i=0; i<=cost.size(); i++){
            minCost.push_back(0);
        }
        minCost[1]=0;
        minCost[2]=0;
        for(int i=2; i<=cost.size(); i++){
            minCost[i]=min(minCost[i-1]+cost[i-1], minCost[i-2]+cost[i-2]);
        }
        return minCost[cost.size()];

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