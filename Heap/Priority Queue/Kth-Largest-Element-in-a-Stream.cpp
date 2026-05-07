#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

class KthLargest
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int i = 0; i < nums.size(); i++)
        {
            add(nums[i]);
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > this->k)
        {
            minHeap.pop();
        }

        return minHeap.top();
    }
};