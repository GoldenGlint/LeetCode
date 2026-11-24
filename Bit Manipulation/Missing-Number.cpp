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
    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        int ans=0;
        for(int i=0; i<n; i++){
            ans^=nums[i];
            ans^=i;
        }
        ans^=n;
        return ans;
    }
};

int main(){

    Solution sol;
    vector<int> nums1 = {3, 0, 1};
    vector<int> nums2 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout<<sol.missingNumber(nums1)<<endl;
    cout<<sol.missingNumber(nums2)<<endl;
}