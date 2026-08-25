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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        int carry=0;

        while(l1||l2||carry){
            int val1=l1?l1->val:0;
            int val2=l2?l2->val:0;

            int sum=val1+val2+carry;

            carry=sum/10;
            int digit=sum%10;
            curr->next=new ListNode(digit);

            curr=curr->next;

            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }


        }

        return dummy.next;
    }
};

int main()
{
    // 1 -> 2 -> 3 -> 4
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    

    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);

    ListNode* head3 = new ListNode(9);
    head3->next = new ListNode(9);
    head3->next->next = new ListNode(9);
    head3->next->next->next = new ListNode(9);

    ListNode* head4 = new ListNode(9);
    head4->next = new ListNode(9);
    head4->next->next = new ListNode(9);
    head4->next->next->next = new ListNode(9);
    head4->next->next->next->next = new ListNode(9);
    head4->next->next->next->next->next = new ListNode(9);
    head4->next->next->next->next->next->next = new ListNode(9);

    

    Solution sol;

    ListNode* ans=sol.addTwoNumbers(head1,head2);
    cout<<endl;
    ListNode* ans1=sol.addTwoNumbers(head3,head4);

    cout << "\nAfter:" << endl;
    printList(ans);
    cout<<endl;
    printList(ans1);

    
}
