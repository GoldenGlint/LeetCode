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

    bool isWord=false;
    unordered_map<char, trieNode*> children;
    trieNode(){
        this->isWord=false;
    }
};

class WordDictionary {
    trieNode *root;
public:

    WordDictionary() {
        root=new trieNode();
    }
    
    void addWord(string word) {
        trieNode *curr=root;
        for(char c : word){
            if(curr->children.find(c)!=curr->children.end()){
                curr=curr->children[c];
            }
            else{
                curr->children[c]=new trieNode();
                curr=curr->children[c];
            }
            
        }
        curr->isWord=true;
    }
    
    bool searchHelper(string word, trieNode* root){
        trieNode *curr=root;
        int index=0;
        for(char c : word){
            if(c=='.'){
                for (const auto& [c, root] : curr->children) {
                    if(searchHelper(word.substr(1+index), curr->children[c])){
                        return true;
                    }
                }
                return false;

            }
            else if(curr->children.find(c)==curr->children.end()){
                return false;
            }
            else{
                curr=curr->children[c];
            }
            index++;
        }
        
        return curr->isWord;

    }

    bool search(string word) {
        return searchHelper(word, root);
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
