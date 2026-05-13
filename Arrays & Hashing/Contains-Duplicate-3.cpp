#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> u;
        for(int i=0; i<nums.size(); i++){
            if(u.find(nums[i])!=u.end()){
                return true;
            }
            u.insert(nums[i]);
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> v1= {1,2,3,1};
    vector<int> v2= {1,2,3,4};
    cout<<sol.containsDuplicate(v1)<<endl;
    cout<<sol.containsDuplicate(v2)<<endl;
}