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

ListNode *toLinkedList(vector<int> arr)
{
    if (arr.empty())
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (int i = 1; i < arr.size(); i++)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode*slow=&dummy;
        ListNode*fast=&dummy;

        for(int i=0; i<=n; i++){
            fast=fast->next;
        }

        while(fast){
            fast=fast->next;
            slow=slow->next;
        }

        slow->next=slow->next->next;

        return dummy.next;


    }
};

int main()
{
    // 1 -> 2 -> 3 -> 4
    ListNode* head1 = new ListNode(1);
    

    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    Solution sol;

    cout << "Before:" << endl;
    printList(head1);
    printList(head2);



    cout << "\nAfter:" << endl;
    printList(sol.removeNthFromEnd(head1,1));
    printList(sol.removeNthFromEnd(head2,2));

    
}
