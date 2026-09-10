#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    string word;

    TrieNode() {
        isWord = false;
        word = "";

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution{
    TrieNode* root;
    vector<string> result;
    public:
    Solution() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isWord = true;
        curr->word = word;
    }
    void dfs(vector<vector<char>>& board,
             int row,
             int col,
             TrieNode* node)
    {
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return;
        }
        char c = board[row][col];

        // Already visited
        if (c == '#') {
            return;
        }

        int index = c - 'a';

        // No word has this prefix
        if (node->children[index] == nullptr) {
            return;
        }

        node = node->children[index];

        if (node->isWord) {
            result.push_back(node->word);

            
            node->isWord = false;
        }
        board[row][col] = '#';
        dfs(board, row + 1, col, node);
        dfs(board, row - 1, col, node);
        dfs(board, row, col + 1, node);
        dfs(board, row, col - 1, node);

        board[row][col] = c;

       
    }

     vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        // Build trie
        for (string word : words) {
            insert(word);
        }

        // Start DFS from every cell
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                dfs(board, row, col, root);
            }
        }

        return result;
        }
};

int main() {
    Solution solution;

    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };

    vector<string> words = {
        "oath",
        "pea",
        "eat",
        "rain"
    };

    vector<string> result = solution.findWords(board, words);

    cout << "Found words:" << endl;

    for (const string& word : result) {
        cout << word << endl;
    }

    return 0;
}