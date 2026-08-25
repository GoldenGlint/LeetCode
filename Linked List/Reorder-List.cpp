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
    void reorderList(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=slow->next;
        slow->next=nullptr;

        ListNode* prev=nullptr;
        ListNode* currNode=second;
        while(currNode){
            ListNode* next=currNode->next;
            currNode->next=prev;
            prev=currNode;
            currNode=next;
        }
        ListNode* start=head;
        while(prev){
            ListNode*temp=start->next;
            ListNode*temp2=prev->next;
            start->next=prev;
            prev->next=temp;
            start=temp;
            prev=temp2;
        }

        
    }
};

int main()
{
    // 1 -> 2 -> 3 -> 4
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

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

    sol.reorderList(head1);
    sol.reorderList(head2);

    cout << "\nAfter:" << endl;
    printList(head1);
    printList(head2);

    
}
