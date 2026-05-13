#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]={0};
        if(s.length()!=t.length()){return false;}
        for(int i=0; i<s.length(); i++){
            arr[s[i]-'a']++;
        }
        for(int i=0; i<s.length(); i++){
            arr[t[i]-'a']--;
        }
        for(auto count:arr){
            if(count!=0){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    cout << sol.isAnagram(s, t) << endl;

    string a = "rat";
    string b = "car";
    cout << sol.isAnagram(a, b) << endl;
}