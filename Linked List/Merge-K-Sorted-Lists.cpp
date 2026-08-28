#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* makeList(vector<int> nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    for (int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }

    ListNode* head = dummy->next;
    delete dummy;

    return head;
}

// Helper: print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        struct Compare{
            bool operator()(ListNode*a, ListNode*b){
                return a->val > b->val;
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        for(ListNode* node : lists){
            if(node){
                pq.push(node);
            }
        }

        ListNode* dummy=new ListNode(0);
        ListNode* currNode=dummy;
        

        while(!pq.empty()){
            ListNode* smallest=pq.top();
            pq.pop();
            currNode->next=smallest;
            currNode=currNode->next;
            if(smallest->next){
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};


int main() {
    ListNode* list1 = makeList({1, 4, 5});
    ListNode* list2 = makeList({1, 3, 4});
    ListNode* list3 = makeList({2, 6});

    vector<ListNode*> lists = {
        list1,
        list2,
        list3
    };

    Solution sol;

    ListNode* result = sol.mergeKLists(lists);

    printList(result);

    return 0;
}