#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap;
        for (int i = 0; i < stones.size(); i++)
        {
            maxHeap.push(stones[i]);
        }
        while (maxHeap.size() > 1)
        {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if (first - second != 0)
            {
                maxHeap.push(first - second);
            }
        }
        if (maxHeap.size() == 1)
        {
            return maxHeap.top();
        }
        return 0;
    }
};