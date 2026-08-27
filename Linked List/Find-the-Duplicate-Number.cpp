#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include <cassert>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow=0;

        while(nums[slow]!=nums[fast]){
            slow=nums[slow];
            fast=nums[fast];
        }

        return nums[fast];
    }
};

void printList(Node* head) {
    Node* curr = head;

    while (curr) {
        cout << "Node: " << curr->val;

        if (curr->random)
            cout << ", Random: " << curr->random->val;
        else
            cout << ", Random: null";

        cout << endl;

        curr = curr->next;
    }
}

int main() {
    Solution sol;
    vector<int> nums1={1,3,4,2,2};
    vector<int> nums2={3,1,3,4,2};
    vector<int> nums3={3,3,3,3,3};

    cout<<sol.findDuplicate(nums1)<<endl;
    cout<<sol.findDuplicate(nums2)<<endl;
    cout<<sol.findDuplicate(nums3)<<endl;
}