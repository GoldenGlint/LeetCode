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
    
    int maxDepth(TreeNode *root)
    {
        if (root)
        {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
        else
        {
            return 0;
        }
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root->left && root->right)
        {
            int best = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
            return max(maxDepth(root->left) + maxDepth(root->right), best);
        }
        else if (root->left)
        {
            return max(maxDepth(root) - 1, diameterOfBinaryTree(root->left));
        }
        else if (root->right)
        {
            return max(maxDepth(root) - 1, diameterOfBinaryTree(root->right));
        }
        else
        {
            return 0;
        }
    }
};