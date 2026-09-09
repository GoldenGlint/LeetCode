#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>

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
    int ans=INT_MIN;
public:
    int maxPath(TreeNode* root){
        if(!root){
            return 0;
        }
        int left=max(0, maxPath(root->left));
        int right=max(0, maxPath(root->right));
        ans=max(ans, left+right+root->val);

        return root->val+max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return ans;
    }
};

int main(){

    Solution sol;

    TreeNode* test=new TreeNode(1);
    test->left=new TreeNode(2);
    test->right=new TreeNode(3);


    TreeNode* test1=new TreeNode(-10);
    test1->left=new TreeNode(9);
    test1->right=new TreeNode(20);
    test1->right->left=new TreeNode(15);
    test1->right->right=new TreeNode(7);

    cout<<sol.maxPathSum(test)<<endl;
    cout<<sol.maxPathSum(test1)<<endl;

}