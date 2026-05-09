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
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=0; i<nums.size(); i++){
            x^=nums[i];
        }
        return x;
    }
};
int main(){

    Solution sol;
    vector<int> nums1={2,2,1};
    vector<int> nums2={4,1,2,1,2};
    cout<<sol.singleNumber(nums1)<<endl;
    cout<<sol.singleNumber(nums2)<<endl;
}