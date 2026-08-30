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
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        queue<TreeNode*> q;

        if(!root){
            return ans;
        }

        q.push(root);

        while(!q.empty()){

            int len=q.size();
            int last;

            for(int i=0; i<len; i++){
                
                //printQueue(q);
                TreeNode* curr=q.front(); 
                q.pop();

                last=curr->val;

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }

            ans.push_back(last);
        }

        return ans;

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

int main(){

    Solution sol;

    TreeNode* test=new TreeNode(1);
    test->left=new TreeNode(2);
    test->right=new TreeNode(3);
    test->right->right=new TreeNode(4);
    test->left->right=new TreeNode(5);

    TreeNode* test1=new TreeNode(1);
    test1->left=new TreeNode(2);
    test1->right=new TreeNode(3);
    test1->left->left=new TreeNode(4);
    test1->left->left->left=new TreeNode(5);

    vector<int> ans;
    ans=sol.rightSideView(test);
    printVector(ans);
    cout<<"seperator"<<endl;
    vector<int> ans1;
    ans1=sol.rightSideView(test1);
    printVector(ans1);

}