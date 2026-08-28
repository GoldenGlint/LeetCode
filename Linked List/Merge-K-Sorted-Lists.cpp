#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

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

bool checkCond(vector<ListNode*>& lists){
            bool res=false;
            for(int i=0; i<lists.size(); i++){
                if(lists[i]){
                    return true;
                }
            }
            return res;
        };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* dummy=new ListNode(0);
        ListNode* currNode=dummy;
        while(checkCond(lists)){
            pair<int, int>min={INT_MAX, -1};
            for(int i=0; i<lists.size(); i++){
                
                if(!lists[i]){
                    continue;
                }
                if(lists[i]->val<min.first){
                    min={lists[i]->val, i};

                }
            }
            currNode->next=lists[min.second];
            lists[min.second]=lists[min.second]->next;
            currNode=currNode->next;
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