#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;


void backtrack(int start, unordered_map<char,string> &m, vector<string> &ans, string &digits, string &curr){
    if(curr.size()==digits.size()){
        ans.push_back(curr);
        return;
    }
    
    string p=m[digits[start]];
    for(int l=0; l<p.size(); l++){
        curr+=p[l];
        backtrack(start+1, m, ans, digits, curr);
        curr=curr.substr(0, curr.size()-1);
    }
    
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        string curr="";
        vector<string> ans;
        backtrack(0, m, ans, digits, curr);
        return ans;
    }
};

int main() {
    Solution sol;
    string s="23";
    vector<string> result = sol.letterCombinations(s);
    cout<<"[";
    for(int i=0; i<result.size(); i++){
        if(i==result.size()-1){
            cout<<result[i];
        }
        else{
            cout<<result[i]<<" ";
        }
    }
    cout<<"]";

    string s1="2";
    vector<string> result1 = sol.letterCombinations(s1);
    cout<<"[";
    for(int i=0; i<result1.size(); i++){
        if(i==result1.size()-1){
            cout<<result1[i];
        }
        else{
            cout<<result1[i]<<" ";
        }
    }
    cout<<"]";

    
}