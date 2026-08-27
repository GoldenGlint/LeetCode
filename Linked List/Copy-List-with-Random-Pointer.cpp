#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include <cassert>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        Node*curr=head;
        unordered_map<Node*, Node*> copies;

        while(curr){
            copies[curr]=new Node(curr->val);
            curr=curr->next;
        }

        curr=head;

        while(curr){
            copies[curr]->next=copies[curr->next];
            copies[curr]->random=copies[curr->random];
            curr=curr->next;
        }
        return copies[head];
    }
};

void printList(Node* head) {
    Node* curr = head;

    while (curr) {
        cout << "Node: " << curr->val;

        if (curr->random)
            cout << ", Random: " << curr->random->val;
        else
            cout << ", Random: null";

        cout << endl;

        curr = curr->next;
    }
}

int main() {
    // Create:
    // 1 -> 2 -> 3

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);

    a->next = b;
    b->next = c;

    // Random pointers:
    // 1.random -> 3
    // 2.random -> 1
    // 3.random -> 2

    a->random = c;
    b->random = a;
    c->random = b;

    cout << "Original:" << endl;
    printList(a);

    Solution sol;
    Node* copied = sol.copyRandomList(a);

    cout << "\nCopied:" << endl;
    printList(copied);

    return 0;
}