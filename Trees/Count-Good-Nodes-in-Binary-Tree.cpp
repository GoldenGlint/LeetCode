#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <cassert>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printQueue(queue<TreeNode*> q) {
    while (!q.empty()) {
        std::cout << q.front()->val << " ";
        q.pop(); // Destroys the copy, not the original
    }
    std::cout << "\n";
}

class Solution {   
public:
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }

        int counter=0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});

        while(!q.empty()){
            TreeNode *curr=q.front().first;
            int maxSoFar=q.front().second;
            q.pop();

            if(curr->val>=maxSoFar){
                counter++;
            }

            int newMax=max(maxSoFar, curr->val);

            if(curr->left){
                q.push({curr->left, newMax});
            }
            if(curr->right){
                q.push({curr->right, newMax});
            }
        }
        return counter;
    }
};

void printVector(vector<int> ans){
    cout<<"[";
    for(int i=0; i<ans.size(); i++){
        
        if(i<ans.size()-1){
            cout<<ans[i]<<",";
        }
        else{
            cout<<ans[i];
        }
        
    }
    cout<<"]"<<endl;
};

int main()
{
    Solution sol;

    // Test 1
    //
    //        3
    //       / \
    //      1   4
    //     /   / \
    //    3   1   5
    //
    // Expected: 4

    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(3);
    root1->right->left = new TreeNode(1);
    root1->right->right = new TreeNode(5);

    int result1 = sol.goodNodes(root1);

    cout << "Test 1: " << result1 << endl;
    assert(result1 == 4);


    // Test 2
    //
    //        3
    //       /
    //      3
    //     / \
    //    4   2
    //
    // Expected: 3

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(2);

    Solution sol2;

    int result2 = sol2.goodNodes(root2);

    cout << "Test 2: " << result2 << endl;
    assert(result2 == 3);


    // Test 3
    //
    // Single node
    //
    // Expected: 1

    TreeNode* root3 = new TreeNode(1);

    Solution sol3;

    int result3 = sol3.goodNodes(root3);

    cout << "Test 3: " << result3 << endl;
    assert(result3 == 1);


    // Test 4
    //
    //       -1
    //       /
    //     -2
    //     /
    //   -3
    //
    // Expected: 1

    TreeNode* root4 = new TreeNode(-1);
    root4->left = new TreeNode(-2);
    root4->left->left = new TreeNode(-3);

    Solution sol4;

    int result4 = sol4.goodNodes(root4);

    cout << "Test 4: " << result4 << endl;
    assert(result4 == 1);


    cout << "\nAll tests passed!" << endl;

    return 0;
}