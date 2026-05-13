#include <iostream>;
#include <vector>;
#include <unordered_map>;

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(target-nums[i])!=m.end()){
                return {m[target-nums[i]] ,i};
            }
            m[nums[i]]=i;
        }
        return {0, 0};
    }
};

int main(){ 
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    
}