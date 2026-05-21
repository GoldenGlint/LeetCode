#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> normal;
    stack<int> minStack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        normal.push(val);
        if (minStack.empty())
        {
            minStack.push(val);
        }
        else
        {
            if (minStack.top() > val)
            {
                minStack.push(val);
            }
            else
            {
                minStack.push(minStack.top());
            }
        }
    }

    void pop()
    {
        normal.pop();
        minStack.pop();
    }

    int top()
    {
        return normal.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{

    MinStack *obj = new MinStack();
    obj->push(5);
    obj->push(3);
    obj->push(4);

    int param_3 = obj->top();
    int param_4 = obj->getMin();
    cout << param_3 << " " << param_4 << endl;
}