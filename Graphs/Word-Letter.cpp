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
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if(!words.count(endWord)){
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto [word, c] = q.front();
            q.pop();
            for(int i=0; i<word.size(); i++){
                char og=word[i];
                for(char b='a'; b<='z'; b++){
                    word[i]=b;
                    if(word==endWord){
                        return c+1;
                    }
                    if(words.count(word)){
                        q.push({word, c+1});
                        words.erase(word);
                    }
                }
                word[i]=og;
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