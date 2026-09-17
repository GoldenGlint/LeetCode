#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

bool isPalindrome(string s){
    int start=0;
    int end=s.length()-1;
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void backtrack(int start, vector<string> &partitions, vector<vector<string>> &ans, string &s){
    if(start==s.size()){
        ans.push_back(partitions);
    }
    for(int i=start; i<s.size(); i++){
        string curr=s.substr(start, i-start+1);
        if(!isPalindrome(curr)){
            continue;
        }
        partitions.push_back(curr);
        backtrack(i+1, partitions, ans, s);
        partitions.pop_back();
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        string current="";
        vector<string> partitions;
        backtrack(0, partitions, ans, s);
        return ans;
    }
};

int main() {
    Solution sol;
    string s="aab";
    vector<vector<string>> result = sol.partition(s);

    for (auto& v : result) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i + 1 < v.size()) cout << ", ";
        }
        cout << "]\n";
    }
}