#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector> 

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[left]){
                if(nums[left]<=target&&target<nums[mid]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{
                if(nums[right]>=target&&target>nums[mid]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};

int main(){

    Solution sol;
    vector<int> v1= {4,5,6,7,0,1,2};
    cout<<sol.search(v1,0)<<endl;
    cout<<sol.search(v1,3)<<endl;
}