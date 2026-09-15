#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

void backtrack(string &forward, string &backward, string &curr, vector<string> &ans, int n){
    
    if(curr.size()==n*2){
        ans.push_back(curr);
        return;
    }

    if(!forward.empty()){
        forward=forward.substr(0, forward.size()-1);
        curr+="(";
        backtrack(forward, backward, curr, ans, n);
        forward+="(";
        curr=curr.substr(0, curr.size()-1);
    }

    if(!backward.empty()&&backward.size()>forward.size()){
        backward=backward.substr(0, backward.size()-1);
        curr+=")";
        backtrack(forward, backward, curr, ans, n);
        backward+=")";
        curr=curr.substr(0, curr.size()-1);
    }
    
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string forward="";
        string backward="";
        string current="";
        for(int i=0; i<n; i++){
            forward+="(";
        }
        for(int i=0; i<n; i++){
            backward+=")";
        }
        backtrack(forward, backward, current, ans, n);
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