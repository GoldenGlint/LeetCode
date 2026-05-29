#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> t;
        for(int i=0; i<s.length(); i++){
            if(s[i]==']'){
                if(!t.empty()){
                    if(t.top()=='['){
                        t.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else if(s[i]==')'){
                if(!t.empty()){
                    if(t.top()=='('){
                        t.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(!t.empty()){
                    if(t.top()=='{'){
                        t.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else{
                t.push(s[i]);
            }
        }
        
        if(t.empty()){
            return true;
        }
        return false;
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