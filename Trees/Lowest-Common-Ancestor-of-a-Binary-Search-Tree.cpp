#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <utility>

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

class Solution
{
public:
    bool contains(TreeNode *root, int value){
        if(!root){
            return false;
        }
        if(root->val==value){
            return true;
        }
        return contains(root->left, value)||contains(root->right, value);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val < root->val && q->val < root->val){
                root=root->left;
            }
            else if(p->val > root->val && q->val > root->val){
                root=root->right;
            }
            else{
                return root;
            }
        }

        return nullptr;
    }
};

int main() {
    /*
                6
              /   \
             2     8
            / \   / \
           0   4 7   9
              / \
             3   5
    */

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution sol;

    // Example 1:
    // p = 2, q = 8
    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* answer = sol.lowestCommonAncestor(root, p, q);

    cout << "LCA of " << p->val << " and " << q->val
         << " = " << answer->val << endl;

    // Expected: 6


    // Example 2:
    // p = 2, q = 4
    p = root->left;
    q = root->left->right;

    answer = sol.lowestCommonAncestor(root, p, q);

    cout << "LCA of " << p->val << " and " << q->val
         << " = " << answer->val << endl;

    // Expected: 2

    return 0;
}