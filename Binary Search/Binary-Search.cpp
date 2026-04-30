#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int upper=nums.size()-1;
        int lower=0;

        while(lower<=upper){
            int middle=(lower+upper)/2;
            if(nums[middle]==target){
                return middle;
            }
            else if(nums[middle]>target){
                upper=middle-1;
            }
            else{
                lower=middle+1;
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
