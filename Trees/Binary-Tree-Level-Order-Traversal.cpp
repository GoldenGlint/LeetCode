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
        
        vector<int> level;
        while(!q.empty()){
            vector<int> level;
            int qSize=q.size();
            for(int i=0; i<qSize; i++){
                TreeNode* temp=q.front();
                level.push_back(temp->val);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(level);
        }
        
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