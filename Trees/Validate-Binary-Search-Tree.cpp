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
    bool wrapper(TreeNode* root, long long minn, long long maxx){
         if(root==nullptr){
            return true;
        }
        if(root->left&&root->right){
            if(root->right->val<=root->val||root->left->val>=root->val){
                return false;
            }
            if(root->right->val>=maxx){
                return false;
            }
            if(root->left->val<=minn){
                return false;
            }
            return wrapper(root->left, minn, root->val)&&wrapper(root->right, root->val, maxx);
        }
        else if(root->right){
            if(root->right->val<=root->val){
                return false;
            }
            if(root->right->val>=maxx){
                return false;
            }
            return wrapper(root->right, root->val, maxx);
        }
        else if(root->left){
            if(root->left->val>=root->val){
                return false;
            }
            if(root->left->val<=minn){
                return false;
            }
            return wrapper(root->left, minn, root->val);
        }
        else{
            return true;
        }
    }
    bool isValidBST(TreeNode* root) {
       return wrapper(root, LLONG_MIN, LLONG_MAX);
    }
};

int main(){
    Solution sol;
    TreeNode* root1 = new TreeNode(2);

    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(5);

    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);

    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    TreeNode* root3 = new TreeNode(2);

    root3->left = new TreeNode(2);
    root3->right = new TreeNode(2);

    TreeNode* root4 = new TreeNode(5);

    root4->left = new TreeNode(4);
    root4->right = new TreeNode(6);

    root4->right->left = new TreeNode(3);
    root4->right->right = new TreeNode(7);

    cout << sol.isValidBST(root4) << endl;

    cout<<sol.isValidBST(root1)<<endl;
    cout<<sol.isValidBST(root2)<<endl;
    cout<<sol.isValidBST(root3)<<endl;

}