#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

void printPQ(priority_queue<int, vector<int>, greater<int>> pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<nums.size(); i++){
            
            pq.push(nums[i]);
             
            
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        
        return pq.top();
    }
};

int main(){

    Solution sol;
    
    vector<int> nums = {3,2,1,5,6,4};
    vector<int> nums1 = {3,2,3,1,2,4,5,5,6};

    cout<<sol.findKthLargest(nums, 2)<<endl;
    cout<<sol.findKthLargest(nums1, 4)<<endl;

    
}