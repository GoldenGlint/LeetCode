#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

class trieNode{
    public:

    bool isWord;
    trieNode* children[26];

    trieNode() {
        isWord = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
    trieNode *root;
public:

    WordDictionary() {
        root=new trieNode();
    }
    
    
     void addWord(string word) {
        trieNode* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new trieNode();
            }

            curr = curr->children[index];
        }

        curr->isWord = true;
    }
    
   bool searchHelper(const string& word, int index, trieNode* curr) {
        if (index == word.size()) {
            return curr->isWord;
        }

        char c = word[index];

        if (c == '.') {

            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr) {

                    if (searchHelper(word, index + 1, curr->children[i])) {
                        return true;
                    }
                }
            }

            return false;
        }

        int childIndex = c - 'a';

        if (curr->children[childIndex] == nullptr) {
            return false;
        }

        return searchHelper(
            word,
            index + 1,
            curr->children[childIndex]
        );
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main(){
    WordDictionary* wordDictionary = new WordDictionary();

    wordDictionary->addWord("at");
    wordDictionary->addWord("and");
    wordDictionary->addWord("an");
    wordDictionary->addWord("add");

    cout << wordDictionary->search("a") << endl;
    cout << wordDictionary->search(".at") << endl;

    wordDictionary->addWord("bat");

    cout << wordDictionary->search(".at") << endl;
    cout << wordDictionary->search("an.") << endl;
    cout << wordDictionary->search("a.d.") << endl;
    cout << wordDictionary->search("b.") << endl; //this one is breaking
    cout << wordDictionary->search("a.d") << endl;
    cout << wordDictionary->search(".") << endl;
}
