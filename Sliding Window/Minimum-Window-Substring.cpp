#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.length()<t.length()){
            return "";
        }

        vector<int> need(128, 0);

        for (char c : t) {
            need[c]++;
        }
        
        int missing = t.length();

        int left = 0;

        int bestLeft = 0;
        int bestLength = INT_MAX;

  for (int right = 0; right < s.length(); right++) {

            // If we actually needed this character,
            // we have satisfied one requirement
            if (need[s[right]] > 0) {
                missing--;
            }

            // Add s[right] to the window
            need[s[right]]--;

            // Window contains everything we need
            while (missing == 0) {

                int currentLength = right - left + 1;

                if (currentLength < bestLength) {
                    bestLength = currentLength;
                    bestLeft = left;
                }

                // Remove s[left] from the window
                need[s[left]]++;

                // If it becomes > 0, we are now missing
                // this character again
                if (need[s[left]] > 0) {
                    missing++;
                }

                left++;
            }
        }

             if (bestLength == INT_MAX) {
            return "";
        }

        return s.substr(bestLeft, bestLength);

    }
};


int main()
{


    Solution sol;
    string s="cabwefgewcwaefgc";
    string t="cae";
    string s1="abc";
    string t1="ab";
    string s2="a";
    string t2="aa";

    cout<<sol.minWindow(s,t)<<endl;
    cout<<sol.minWindow(s1,t1)<<endl;
    cout<<sol.minWindow(s2,t2)<<endl;
 

}