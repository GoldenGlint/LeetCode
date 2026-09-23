#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <utility>
#include <math.h>

#include <cassert>
using namespace std;

class Solution {
public:
    bool checkValid(string s1, string s2){
        if(s1.length()!=s2.length()||s1==s2){return false;}

        int c=0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i]!=s2[i]){
                c++;
            }
        }
        return c==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord)==wordList.end()){
            return false;
        }
        vector<int> tracker(wordList.size()+1, INT_MAX);
        queue<tuple<int, int, string>> q;
        q.push({-1, 1, beginWord});
        while(!q.empty()){
            auto[index, counter, currWord]=q.front();
            q.pop();
            for(int i=0; i<wordList.size(); i++){
                if(checkValid(currWord, wordList[i])&&(counter+1)<tracker[i]){
                    tracker[i]=counter+1;
                    q.push({i, counter+1, wordList[i]});
                }
            }
        }
        for(int i=0; i<wordList.size(); i++){
            if(wordList[i]==endWord){
                return tracker[i]==INT_MAX ? 0 : tracker[i];
            }
        }
        return 0;

        
    }
};

int main() {
    Solution sol;

    // Example 1
    string beginWord1 = "hit";
    string endWord1 = "cog";
    vector<string> wordList1 = {
        "hot", "dot", "dog", "lot", "log", "cog"
    };

    cout << "Test 1: "
         << sol.ladderLength(beginWord1, endWord1, wordList1)
         << endl;

    // Expected: 5


    // Example 2
    string beginWord2 = "hit";
    string endWord2 = "cog";
    vector<string> wordList2 = {
        "hot", "dot", "dog", "lot", "log"
    };

    cout << "Test 2: "
         << sol.ladderLength(beginWord2, endWord2, wordList2)
         << endl;

    // Expected: 0

    return 0;
}