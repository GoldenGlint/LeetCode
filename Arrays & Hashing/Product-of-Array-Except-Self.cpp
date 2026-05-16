#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> output(nums.size(), 1);
        int prefix=1;
        for(int i=0; i<nums.size(); i++){
            output[i]*=prefix;
            prefix*=nums[i];
        }     

        int suffix=1;

        for(int i=nums.size()-1; i>=0; i--){
            output[i]*=suffix;
            suffix*=nums[i];
        } 

        return output;
    }
};

int main(){
    Solution sol;
    vector<int> v1={1,2,3,4};
    vector<int> v2={-1,1,0,-3,3};
    vector<int> sol1=sol.productExceptSelf(v1);
    vector<int> sol2=sol.productExceptSelf(v2);

    cout << "v1 output: ";
    for (int x : sol1) cout << x << " ";
    cout << endl;

    cout << "v2 output: ";
    for (int x : sol2) cout << x << " ";
    cout << endl;

   

}