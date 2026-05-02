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
// --- Helper utilities ---

ListNode* toList(const std::vector<int>& arr) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int val : arr) {
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return dummy.next;
}

std::vector<int> toArray(ListNode* node) {
    std::vector<int> result;
    while (node) {
        result.push_back(node->val);
        node = node->next;
    }
    return result;
}

void freeList(ListNode* node) {
    while (node) {
        ListNode* tmp = node;
        node = node->next;
        delete tmp;
    }
}



class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode* dummy = new ListNode(0);  // heap, not stack
        ListNode* curr = dummy;
        while (list1 != nullptr || list2 != nullptr)
        {
            if (list1 == nullptr)
            {
                curr->next = list2;
                break;
            }
            else if (list2 == nullptr)
            {
                curr->next = list1;
                break;
            }
            if (list1->val <= list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
                curr = curr->next;
            }
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

void runTest(int caseNum, std::vector<int> l1, std::vector<int> l2, std::vector<int> expected) {
    ListNode* list1 = toList(l1);
    ListNode* list2 = toList(l2);
    Solution sol;

    ListNode* result = sol.mergeTwoLists(list1, list2);
    std::vector<int> resultArr = toArray(result);

    bool passed = resultArr == expected;
    std::cout << (passed ? "✅ PASS" : "❌ FAIL");
    std::cout << " | Case " << caseNum << ": l1=[";
    for (int i = 0; i < l1.size(); i++) std::cout << (i ? "," : "") << l1[i];
    std::cout << "] l2=[";
    for (int i = 0; i < l2.size(); i++) std::cout << (i ? "," : "") << l2[i];
    std::cout << "] → [";
    for (int i = 0; i < resultArr.size(); i++) std::cout << (i ? "," : "") << resultArr[i];
    std::cout << "]\n";

    if (!passed) {
        std::cout << "         Expected: [";
        for (int i = 0; i < expected.size(); i++) std::cout << (i ? "," : "") << expected[i];
        std::cout << "]\n";
    }

    freeList(result);
}

int main() {
    runTest(1, {1, 2, 4},  {1, 3, 4},  {1, 1, 2, 3, 4, 4});  // standard merge
    runTest(2, {},          {0},         {0});                  // one empty list
    runTest(3, {},          {},          {});                   // both empty
    runTest(4, {1},         {2},         {1, 2});               // single elements
    runTest(5, {2},         {1},         {1, 2});               // reverse order
    runTest(6, {1, 3, 5},  {2, 4, 6},  {1, 2, 3, 4, 5, 6});  // perfectly interleaved
    runTest(7, {1, 1, 1},  {1, 1, 1},  {1, 1, 1, 1, 1, 1});  // all duplicates
    runTest(8, {1},         {},          {1});                  // other list empty

    return 0;
}