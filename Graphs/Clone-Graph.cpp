#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <utility>
#include <math.h>

#include <cassert>
using namespace std;





// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



class Solution {
public:
    unordered_map<Node*, Node*> clone;
    Node* dfs(Node* node){
        if (node == nullptr) {
            return nullptr;
        }
        if(clone.count(node)){
            return clone[node];
        }

        Node* c=new Node(node->val);
        clone[node]=c;
        for(int i=0; i<node->neighbors.size(); i++){
            Node*temp=dfs(node->neighbors[i]);
            c->neighbors.push_back(temp);
        }
        return c;

    };
    Node* cloneGraph(Node* node) {
        Node* ans= dfs(node);
        return ans;
    }
};



int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);

    n1->neighbors.push_back(n2);
    n2->neighbors.push_back(n1);

    Solution sol;
    Node* clone = sol.cloneGraph(n1);

    cout << "Original value: " << n1->val << endl;
    cout << "Clone value: " << clone->val << endl;

    cout << "Original neighbor: "
         << n1->neighbors[0]->val << endl;

    cout << "Clone neighbor: "
         << clone->neighbors[0]->val << endl;

    cout << "Same starting pointer? "
         << (n1 == clone) << endl;

    cout << "Same neighbor pointer? "
         << (n2 == clone->neighbors[0]) << endl;
}