#include <iostream>;
#include <vector>;
#include <unordered_map>;

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> vals;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (vals.find(complement) != vals.end())
            {
                return {vals[complement], i};
            }
            vals[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
