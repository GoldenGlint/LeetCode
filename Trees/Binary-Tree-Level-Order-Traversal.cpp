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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        
        queue <TreeNode *> q;
        q.push(root);
        int counter=0;
        int prevtarget=1;
        int newtarget=0;
        vector<int> level;
        while(!q.empty()){
            printQueue(q);
            if(counter==prevtarget){
                ans.push_back(level);
                level={};
                prevtarget=newtarget;
                newtarget=0;
                counter=0;
            }
            else{
                TreeNode* curr=q.front();
                q.pop();
                counter++;
                level.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                    newtarget++;
                }
                if(curr->right){
                    q.push(curr->right);
                    newtarget++;
                }
            }
        }
        ans.push_back(level);
        return ans;
    }
};

void printVector(vector<vector<int>> ans){
    cout<<"[";
    for(int i=0; i<ans.size(); i++){
        cout<<"[";
        for(int l=0; l<ans[i].size(); l++){
            if(l<ans[i].size()-1){
                cout<<ans[i][l]<<",";
            }
            else{
                cout<<ans[i][l];
            }
            
        }
        if(i<ans.size()-1){
            cout<<"],";
        }
        else{
            cout<<"]";
        }
        
    }
    cout<<"]";
};

int main(){

    Solution sol;

    TreeNode* test=new TreeNode(3);
    test->left=new TreeNode(9);
    test->right=new TreeNode(20);
    test->right->left=new TreeNode(15);
    test->right->right=new TreeNode(7);

    vector<vector<int>> ans;
    ans=sol.levelOrder(test);
    printVector(ans);

}