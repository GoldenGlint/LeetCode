#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
       
        while(start<=end){
            int index=(start+end)/2;
            if(nums[index]==target){
                return index;
            }
            else if(nums[index]>target){
                end=index-1;
            }
            else{
                start=index+1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    cout << sol.search(nums, 9) << endl;
    cout << sol.search(nums1, -2) << endl;
}