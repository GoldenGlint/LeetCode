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

        for(int num: nums){
            sum+=num;
        }

        if(sum%2==1){
            return false;
        }

        vector<bool> ans(sum+1, false);
        ans[0]=true;
        ans[sum]=true;
        int target=sum/2;
        
        for(int num : nums){
            for(int l=target; l>=num; l--){
                ans[l]=ans[l]||ans[l-num];
            }
        }

        return ans[target];

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