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
    unordered_map<char, trieNode*> children;
    bool isWord=false;
    trieNode(){
        this->isWord=false;
    }
};

class Trie {
    trieNode* root;
public:
    Trie(){
        root=new trieNode();
    }
    
    void insert(string word) {
        trieNode* curr=root;
        for(char c: word){
            if(curr->children.find(c)==curr->children.end()){
                curr->children[c]=new trieNode();
            }
            curr=curr->children[c];
        }
        curr->isWord=true;
    }
    
    bool search(string word) {
        trieNode* curr=root;

        for(char c: word){

            if(curr->children.find(c)==curr->children.end()){
                return false;
            }

            curr=curr->children[c];
        }

        if(curr->isWord){
            return true;
        }

        return false;

    }
    
    bool startsWith(string prefix) {

        trieNode* curr=root;

        for(char c: prefix){

            if(curr->children.find(c)==curr->children.end()){
                return false;
            }

            curr=curr->children[c];
        }

        return true;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main(){
    Trie *trie = new Trie();
    trie->insert("apple");
    cout<<trie->search("apple")<<endl;   // return True
    cout<<trie->search("app")<<endl;     // return False
    cout<<trie->startsWith("app")<<endl; // return True
    trie->insert("app");
    cout<<trie->search("app")<<endl; // return True
}
