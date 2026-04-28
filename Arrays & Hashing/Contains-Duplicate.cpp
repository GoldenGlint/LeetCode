#include <iostream>;
#include <vector>;
#include <unordered_map>;

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> tracker;
        for(int i=0; i<nums.size(); i++){
            if(tracker.find(nums[i])!=tracker.end()){
                return true;
            }
            tracker[nums[i]]=1;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout<<sol.containsDuplicate(nums)<<endl;
    vector<int> nums1 = {1, 2, 3, 4};
    cout<<sol.containsDuplicate(nums1)<<endl;
    vector<int> nums2 = {1,1,1,3,3,4,3,2,4,2};
    cout<<sol.containsDuplicate(nums2)<<endl;

    
}
