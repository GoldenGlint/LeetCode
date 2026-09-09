#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <sstream>
#include <string> // Required header

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

class Codec {
public:
    
    string serialize(TreeNode* root) {

        string ans="[";
        queue <TreeNode*> q;
        vector<string> tokens;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(!curr){
                tokens.push_back("null");
            }
            else{
                tokens.push_back(to_string(curr->val));
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        while(!tokens.empty() && tokens.back()=="null"){
            tokens.pop_back();
        }
        for(int i=0; i<tokens.size(); i++){
            ans+=tokens[i]+",";
        }
        ans[ans.size()-1]=']';
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string clean;
        for(int i=1; i<data.size()-1; i++){
            clean+=data[i];
        }
        vector<string> result;
        stringstream ss(clean);
        string token;

        while(getline(ss, token, ',')){
            result.push_back(token);
        }

        if (result.empty()) {
            return nullptr;
        }

        queue<TreeNode*> q; //store the current node we are processing
        int index=1;
        TreeNode* root=new TreeNode(stoi(result[0]));
        q.push(root);
        
        while(!q.empty()&&index<result.size()){
        
            TreeNode*curr=q.front();
            q.pop();

            if(index<result.size() && result[index]!="null"){
                curr->left=new TreeNode(stoi(result[index]));
                q.push(curr->left);
            }
            index++;
            if(index<result.size() && result[index]!="null"){
                curr->right=new TreeNode(stoi(result[index]));
                q.push(curr->right);
            }
            index++;
            
        }

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

    vector<string> result;

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr) {
            result.push_back(to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        } else {
            result.push_back("null");
        }
    }

    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << ",";
        }
    }

    cout << "]" << endl;
}

int main() {
    Codec codec;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string encoded = codec.serialize(root);

    cout << "Serialized: " << encoded << endl;

    string an="[1,2,3,null,null,4,5]";
        TreeNode* deSerialized = codec.deserialize(an);

    cout << "Deserialized tree: ";
    printTree(deSerialized);

    

    return 0;
}