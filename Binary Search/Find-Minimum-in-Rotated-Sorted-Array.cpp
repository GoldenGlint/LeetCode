#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int index=(s+e)/2;
        while(s<e){
            index=(s+e)/2;
            
            if(nums[index]>nums[e]){
                s=index+1;
            }
            else{
                e=index;
            }
        }
        return nums[s];
    }
};

int main(){
    Solution sol;
    vector<int> v1={3,4,5,1,2};
    vector<int> v2={4,5,6,7,0,1,2};
    vector<int> v3={3,1,2};
    vector<int> v4={11,13,15,17};
    cout<<sol.findMin(v1)<<endl;
    cout<<sol.findMin(v2)<<endl;
    cout<<sol.findMin(v3)<<endl;
    cout<<sol.findMin(v4)<<endl;

}