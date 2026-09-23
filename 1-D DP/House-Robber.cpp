#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> tracker(nums.size(), 0);
        if(nums.size()==1){
            return nums[0];
        }
        else if(nums.size()==2){
            return max(nums[0], nums[1]);
        }
        tracker[0]=nums[0];
        tracker[1]=max(nums[0], nums[1]);
        for(int i=2; i<tracker.size(); i++){
            tracker[i]=max(tracker[i-1], tracker[i-2]+nums[i]);
        }
        return tracker[tracker.size()-1];
    }
};

int main()
{

    Solution sol;
    vector<int> v1={1,2,3,1};
    vector<int> v2={2,7,9,3,1};
    cout<<sol.rob(v1)<<endl;
    cout<<sol.rob(v2)<<endl;
    
}