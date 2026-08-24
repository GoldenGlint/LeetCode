#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int bestLeft = 0;
        int bestLength = INT_MAX;
        string ans="";
        if(s.length()<t.length()){
            return "";
        }

        vector<int> counter(129, 0);

        for(int i=0; i<t.size(); i++){
            counter[t[i]-'A']++;
        }
        
        int left=0;   
        bool valid = true;

        for(int right=0; right<s.length(); right++){

            valid=true;
            counter[s[right]-'A']--;

            for (int x : counter) {
                if (x > 0) {
                    valid = false;
                    break;
                }
            }
               
                while(valid){
                        int currentLength = right - left + 1;

                        if (currentLength < bestLength) {
                            bestLength = currentLength;
                            bestLeft = left;
                        }
                        counter[s[left]-'A']++;
                        left++;
                        if(counter[s[left-1]-'A']>0){
                            valid=false;
                        }
                                            
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