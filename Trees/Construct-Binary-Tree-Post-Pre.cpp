#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <cassert>
#include <optional>
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.empty()||inorder.empty()){
            return nullptr;
        }

        int target=preorder[0];
        TreeNode* root=new TreeNode(target);
        
        preorder.erase(preorder.begin());
        vector<int> left;
        vector<int> right;
        bool found=false;

        for(int i=0; i<inorder.size(); i++){
            if(target==inorder[i]){
                found=true;
            }
            else if(found){
                right.push_back(inorder[i]);
            }
            else{
                left.push_back(inorder[i]);
            }
        }

        root->left=buildTree(preorder, left);
        root->right=buildTree(preorder, right);

        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    vector<optional<int>> result;

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr) {
            result.push_back(curr->val);
            q.push(curr->left);
            q.push(curr->right);
        } else {
            result.push_back(nullopt);
        }
    }

    // Remove unnecessary nulls at the end
    while (!result.empty() && !result.back().has_value()) {
        result.pop_back();
    }

    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        if (result[i].has_value()) {
            cout << result[i].value();
        } else {
            cout << "null";
        }

        if (i != result.size() - 1) {
            cout << ",";
        }
    }

    cout << "]" << endl;
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;

    TreeNode* root = solution.buildTree(preorder, inorder);

    cout << "Expected: [3,9,20,null,null,15,7]" << endl;
    cout << "Actual:   ";
    printTree(root);

    return 0;
}