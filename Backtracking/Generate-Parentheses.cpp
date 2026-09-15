#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

void backtrack(int open, int close,vector<string> &ans, int n, string &curr){
    
    if(curr.length()==n*2){
        ans.push_back(curr);
        return;
    }

    if(open>0){
        curr+="(";
        open--;
        backtrack(open, close, ans, n, curr);
        open++;
        curr=curr.substr(0, curr.size()-1);
    }
    if(close>0 && open<close){
        curr+=")";
        close--;
        backtrack(open, close, ans, n, curr);
        close++;
        curr=curr.substr(0, curr.size()-1);
    }

};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=n;
        int close=n;
        string curr="";
        backtrack(open, close, ans, n, curr);
        return ans;
    }
};

int main() {
    Solution sol;

    int n=3;
    
    vector<string> ans=sol.generateParenthesis(n);
    cout<<"[";
    for(auto v:ans){
        cout<<"[";
        for(int i=0; i<v.size(); i++){
            if(i==v.size()-1){
                cout<<v[i];
            }
            else{
                cout<<v[i];
            }
        }
        cout<<"] ";
    }
    cout<<"]";
}