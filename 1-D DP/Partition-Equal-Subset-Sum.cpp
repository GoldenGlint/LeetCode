#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        vector<bool> ans(sum+1, 0);
        ans[0]=1;
        ans[sum]=1;
        int target=sum/2;
        
        for(auto num : nums){
            for(int l=target; l-num>=0; l--){
                ans[l]=ans[l]||ans[l-num];
            }
        }

        if(ans[target]&&sum%2!=1){
            return true;
        }

        return false;


    }
};

int main()
{
    Solution sol;
    vector<int> v1={1,5,11,5};
    vector<int> v2={1,2,3,5};
    cout<<sol.canPartition(v1)<<endl;
    cout<<sol.canPartition(v2)<<endl;
    
}