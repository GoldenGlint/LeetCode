#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.length() == 1 || s.length() == 0)
        {
            return true;
        }
        s.erase(remove_if(s.begin(), s.end(), [](char c)
                          { return !isalnum(c); }),
                s.end());
        transform(s.begin(), s.end(), s.begin(), [](char c)
                  { return tolower(c); });

        int start = 0;
        int end = s.length() - 1;

        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sol.isPalindrome("race a car") << endl;
    cout << sol.isPalindrome("") << endl;
}