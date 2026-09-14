#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

void backtrack(vector<int> &past, vector<int> &current, vector<vector<int>> &ans){
    if(current.empty()){
        ans.push_back(past);
        return;
    }
    for(int i=0; i<current.size(); i++){
        past.push_back(current[i]);
        int temp=current[i];
        current.erase(current.begin()+i);
        backtrack(past, current, ans);
        current.insert(current.begin()+i, temp);
        past.pop_back();
    }

};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current=nums;
        vector<int> past;
        backtrack(past, current, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    for (auto& v : result) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i + 1 < v.size()) cout << ", ";
        }
        cout << "]\n";
    }
}