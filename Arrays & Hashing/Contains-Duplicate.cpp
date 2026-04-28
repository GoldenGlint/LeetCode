#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        /*unordered_set<int> track;
        for(int i=0; i<nums.size(); i++){
             if(track.find(nums[i])!=track.end()){
                 return true;
             }
             track.insert(nums[i]);
        }
        return false;*/
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << sol.containsDuplicate(nums) << endl;
    vector<int> nums1 = {1, 2, 3, 4};
    cout << sol.containsDuplicate(nums1) << endl;
    vector<int> nums2 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << sol.containsDuplicate(nums2) << endl;
}
