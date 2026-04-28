#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.length()!=t.length()){
            return false;
        }
        int arr[26]={0};

        for(int i=0; i<s.length(); i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }

        for(int a : arr){
            if(a!=0) return false;
        }
        return true;

        /*sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s!=t){
            return false;
        }
        return true;*/
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
