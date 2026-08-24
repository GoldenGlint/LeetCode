#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        vector<int> need(26, 0);
        vector<int> have(26, 0);

        for(int i=0; i<s1.length(); i++){
            need[s1[i]-'a']++;
        }

        for(int i=0; i<s1.length(); i++){
            have[s2[i]-'a']++;
        }

        if(need==have){
            return true;
        }
        int left=0;
        for(int right=s1.length(); right<s2.length(); right++){

            
            have[s2[left]-'a']--;
            have[s2[right]-'a']++;
            left++;

            if(need==have){
                return true;
            }

            
        }
        

        

        return false;

    }
};


int main()
{


    Solution sol;
    string s1="ab";
    string s2="eidbaooo";
    string s3="eidboaoo";
    cout<<sol.checkInclusion(s1, s2)<<endl;
    cout<<sol.checkInclusion(s1, s3)<<endl;


}