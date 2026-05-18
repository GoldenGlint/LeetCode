#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans;
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end)
        {
            if (numbers[start] + numbers[end] > target)
            {
                end--;
            }
            else if (numbers[start] + numbers[end] < target)
            {
                start++;
            }
            else
            {
                break;
            }
        }
        return {start + 1, end + 1};
    }
};

int main()
{
    Solution sol;
    vector<int> result;

    // Test 1: [2,7,11,15], target = 9 → [1,2]
    vector<int> t1 = {2, 7, 11, 15};
    result = sol.twoSum(t1, 9);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;

    // Test 2: [2,3,4], target = 6 → [1,3]
    vector<int> t2 = {2, 3, 4};
    result = sol.twoSum(t2, 6);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;

    // Test 3: [-1,0], target = -1 → [1,2]
    vector<int> t3 = {-1, 0};
    result = sol.twoSum(t3, -1);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;
}