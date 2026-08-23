#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right=0;
        int left=0;

        if(s.length()==0){
            return 0;
        }

        int result=1;
        unordered_map <int,int> counter;
        counter[s[0]]=1;

        while(left!=s.length()-1){
            if(left+1<s.length()&&right+1<s.length()){
                if(counter[s[right+1]]==0){
                    right++;
                    counter[s[right]]++;
                }
                else{
                    counter[s[left]]--;
                    left++;
                }
            }
            else{
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
    string s1="abcabcbb";
    string s2="bbbbb";
    string s3="pwwkew";

    cout<<sol.lengthOfLongestSubstring(s1)<<endl;
    cout<<sol.lengthOfLongestSubstring(s2)<<endl;
    cout<<sol.lengthOfLongestSubstring(s3)<<endl;

}
