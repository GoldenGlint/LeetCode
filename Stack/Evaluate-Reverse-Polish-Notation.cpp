#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<string> numbers;
        int result;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int fnum = stoi(numbers.top());
                numbers.pop();
                int snum = stoi(numbers.top());
                numbers.pop();

                result = snum + fnum;
                numbers.push(to_string(result));
            }
            else if (tokens[i] == "-")
            {
                int fnum = stoi(numbers.top());
                numbers.pop();
                int snum = stoi(numbers.top());
                numbers.pop();

                result = snum - fnum;
                numbers.push(to_string(result));
            }
            else if (tokens[i] == "*")
            {
                int fnum = stoi(numbers.top());
                numbers.pop();
                int snum = stoi(numbers.top());
                numbers.pop();

                result = snum * fnum;
                numbers.push(to_string(result));
            }
            else if (tokens[i] == "/")
            {
                int fnum = stoi(numbers.top());
                numbers.pop();
                int snum = stoi(numbers.top());
                numbers.pop();

                result = snum / fnum;
                numbers.push(to_string(result));
            }
            else
            {
                numbers.push(tokens[i]);
            }
        }
        return stoi(numbers.top());
    }
};

int main()
{
    Solution sol;
    vector<string> n1 = {"2", "1", "+", "3", "*"};
    vector<string> n2 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout<<sol.evalRPN(n1)<<endl;
    cout<<sol.evalRPN(n2)<<endl;
}