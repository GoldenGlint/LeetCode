#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int currMin=nums[0];
        int currMax=nums[0];
        int ans=currMax;
        for(int i=1; i<nums.size(); i++){
            int temp=currMax;
            currMax=max({currMax*nums[i], currMin*nums[i], nums[i]});
            currMin=min({temp*nums[i], currMin*nums[i], nums[i]});
            ans=max(currMax, ans);
        }
        
        return ans;

    }
};

int main()
{

    Solution sol;
    vector<int> v1={2,3,-2,4};
    vector<int> v2={-2,0,-1};
    vector<int> v3={-4,-3,-2};
    cout<<sol.maxProduct(v1)<<endl;
    cout<<sol.maxProduct(v2)<<endl;
    cout<<sol.maxProduct(v3)<<endl;
    
    
}