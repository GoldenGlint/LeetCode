#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> counter;
        int left=0; 
        int maxFreq=0;
        int result=0;

        for(int right=0; right<s.length(); right++){

            counter[s[right]]++;

            maxFreq=max(maxFreq, counter[s[right]]);

            while((right-left+1)-maxFreq>k){
                counter[s[left]]--;
                left++;
            }

            result=max(result, right-left+1);

        }

        return result;

    }
};

int main()
{
    Solution sol;
    string s1="ABAB";
    string s2="AABABBA";
    
    cout<<sol.characterReplacement(s1, 2)<<endl;
    cout<<sol.characterReplacement(s2, 1)<<endl;



}