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
            if (minHeap.size() < k)
            {
                minHeap.push(nums[i]);
            }
            else
            {
                if (nums[i] > minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            }
        }
    }

    int add(int val)
    {
        if (minHeap.size() < this->k)
        {
            minHeap.push(val);
        }
        else if (val > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};