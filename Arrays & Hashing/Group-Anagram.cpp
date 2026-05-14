#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
private:
    string getKey(string str){
        int arr[26]={0};
        for(char c: str){
            arr[c-'a']++;
        }
        string key="";
        for(int i=0; i<26; i++){
            key+='#';
            key+=to_string(arr[i]);
        }
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.empty())
        {
            return {{}};
        }
        vector<vector<string>> sol;
        unordered_map<string, int> m;
        int index = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string key=getKey(strs[i]);
            if (m.find(key) == m.end())
            {
                m[key] = index;
                index++;
                vector<string> t;
                t.push_back(strs[i]);
                sol.push_back(t);
            }
            else
            {
                sol[m[key]].push_back(strs[i]);
            }
        }
        return sol;
    }
};

int main()
{
    Solution sol;
    vector<string> str1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> s = sol.groupAnagrams(str1);
    for (const auto &group : s) 
    {
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }
}