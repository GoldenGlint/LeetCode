#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return {{}};
        }
        vector<vector<string>> sol;
        unordered_map<string, int> m;
        int index = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (m.find(temp) == m.end())
            {
                m[temp] = index;
                index++;
                vector<string> t;
                t.push_back(strs[i]);
                sol.push_back(t);
            }
            else
            {
                sol[m[temp]].push_back(strs[i]);
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