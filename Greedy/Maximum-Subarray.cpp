#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int val = nums[0];
        int largeVal = nums[0];
        int start = 0;
        int end = 0;
        int temp_start = 0;
        if(nums.size()==1){
            return val;
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i]+val<nums[i]){
                val=nums[i];
                start=i;
            }
            else{
                end=i;
                val+=nums[i];
            }
            largeVal=max(largeVal, val);
        }
        return largeVal;

    }
};

int main(){
    Solution sol;
    vector<int> v1={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v2={1};
    vector<int> v3={5,4,-1,7,8};
    cout<<sol.maxSubArray(v1)<<endl;
    cout<<sol.maxSubArray(v2)<<endl;
    cout<<sol.maxSubArray(v3)<<endl;
}