#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

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

void printList(ListNode* head) {
    while (head) {
        cout << head->val;

        if (head->next) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while(true){
            ListNode* kth= groupPrev;
        

            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
                // Fewer than k nodes remain
                if (!kth) {
                    break;
                }
            
            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;

                curr->next = prev;

                prev = curr;
                curr = temp;
            }
            ListNode* oldStart = groupPrev->next;

            groupPrev->next = kth;

            groupPrev = oldStart;

        
        }

        return dummy->next;

    }
};

int main()
{
        Solution sol;

    ListNode* head = makeList({1, 2, 3, 4, 5});

    cout << "Before: ";
    printList(head);

    head = sol.reverseKGroup(head, 2);

    cout << "After:  ";
    printList(head);

    return 0;
}
