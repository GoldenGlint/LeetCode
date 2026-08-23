#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> seen;
        int result=0;
        int left=0;
        for(int right=0; right<s.length(); right++){
            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            result=max(result, right-left+1);
        }

        return result;

    }
};

int main()
{
    Solution sol;
    string s1="abcabcbb";
    string s2="bbbbb";
    string s3="pwwkew";

    cout<<sol.lengthOfLongestSubstring(s1)<<endl;
    cout<<sol.lengthOfLongestSubstring(s2)<<endl;
    cout<<sol.lengthOfLongestSubstring(s3)<<endl;

}
