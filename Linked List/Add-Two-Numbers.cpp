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
        ListNode*curr1=l1;
        ListNode*curr2=l2;
        ListNode dummy(0);
        ListNode*curr=&dummy;
        int carryover=0;
        while(curr1&&curr2){
            int value=curr1->val+curr2->val+carryover;
            carryover=0;
            if(value>9){
                value-=10;
                carryover=1;
            }
            curr->next=new ListNode(value);
            curr1=curr1->next;
            curr2=curr2->next;
            curr=curr->next;
            cout<<value<<endl;
        }
        if(curr1){
            while(curr1){
                int value=curr1->val+carryover;
                carryover=0;
                if(value>9){
                    value-=10;
                    carryover=1;
                }
                curr->next=new ListNode(value);
                curr1=curr1->next;
                curr=curr->next;
                cout<<value<<endl;
                
            }

        }
        else{
            while(curr2){
                int value=curr2->val+carryover;
                carryover=0;
                if(value>9){
                    value-=10;
                    carryover=1;
                }
                curr->next=new ListNode(value);
                curr2=curr2->next;
                curr=curr->next;
                cout<<value<<endl;
            }
        }

        if(carryover){
            curr->next=new ListNode(1);
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
