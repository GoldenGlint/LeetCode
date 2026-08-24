#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int right=0; right<nums.size(); right++){
            while(!dq.empty() && nums[right]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(right);
            if(dq.front()<=right-k){
                dq.pop_front();
            }
            if(right>=k-1){
                ans.push_back(nums[dq.front()]);
            }

        }

    return ans;
    }
};


void printLoop(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{


    Solution sol;
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    printLoop(sol.maxSlidingWindow(nums,3));


}