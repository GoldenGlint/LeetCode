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

class Solution {
public:
    int count=0;
    int answer=0;

    void inOrder(TreeNode* root, int k){
        if(root==nullptr){
            return;
        }
        inOrder(root->left, k);
        count++;
        if(k==count){
            answer=root->val;
            return;
        }
        inOrder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        count=0;
        inOrder(root, k);
        return answer;
    }
};

int main() {
    Solution sol;

    /*
            5
           / \
          3   6
         / \
        2   4
       /
      1
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    cout << sol.kthSmallest(root, 3) << endl; // 3
}