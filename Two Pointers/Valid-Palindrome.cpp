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
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c)
                          { return !isalnum(c); }),
                s.end());

        transform(s.begin(), s.end(), s.begin(), [](unsigned char c)
                  { return tolower(c); });

        int low = 0;
        int high = s.length() - 1;

        while (low < high)
        {
            if (s[low] != s[high])
            {
                return false;
            }
            low++;
            high--;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    cout<<sol.isPalindrome("A man, a plan, a canal: Panama")<<endl;
    cout<<sol.isPalindrome("race a car")<<endl;
    cout<<sol.isPalindrome("")<<endl;
}
