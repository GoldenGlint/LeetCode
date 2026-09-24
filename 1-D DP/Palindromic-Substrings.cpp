#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int counter=0;
        int n=s.length();
        for(int center=0; center<n; center++){
            int l=center;
            int r=center;
            while(l>=0&&r<n&&s[l]==s[r]){
                counter++;
                l--;
                r++;
            }
            l=center;
            r=center+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                counter++;
                l--;
                r++;
            }
        }
        return counter;

    }
};

int main()
{
    Solution sol;
    string s1="abc";
    string s2="aaa";
    cout<<sol.countSubstrings(s1)<<endl;
    cout<<sol.countSubstrings(s2)<<endl;

    
}