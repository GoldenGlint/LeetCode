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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev=nullptr;
        ListNode *curr=head;
        while(curr!=nullptr){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> tests = {
        {1, 2, 3, 4, 5},
        {1, 2},
        {1},
        {},
        {1, 1, 2, 2}};

    for (auto &arr : tests)
    {
        ListNode *head = toLinkedList(arr);
        cout << "Input:  ";
        printList(head);
        ListNode *result = sol.reverseList(head);
        cout << "Output: ";
        printList(result);
        cout << "---\n";
    }
}
