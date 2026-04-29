#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> t;
        if (s.length() == 0)
        {
            return true;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                t.push(s[i]);
            }
            else if (s[i] == '[')
            {
                t.push(s[i]);
            }
            else if (s[i] == '{')
            {
                t.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if(t.empty()){return false;}
                if (t.top() != '(')
                {
                    return false;
                }
                t.pop();
            }
            else if (s[i] == '}')
            {
                if(t.empty()){return false;}
                if (t.top() != '{')
                {
                    return false;
                }
                t.pop();
            }
            else if (s[i] == ']')
            {
                if(t.empty()){return false;}
                if (t.top() != '[')
                {
                    return false;
                }
                t.pop();
            }
            else
            {
                return false;
            }
        }
        if(!t.empty()){
            return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isValid("()") << endl;
    cout << sol.isValid("()[]{}") << endl;
    cout << sol.isValid("(]") << endl;
    cout << sol.isValid("([])") << endl;
    cout << sol.isValid("([)]") << endl;
}
