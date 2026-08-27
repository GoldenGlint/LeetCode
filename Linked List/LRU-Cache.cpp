#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include <cassert>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LRUCache {
public:
    class Node{
        public:
            int key;
            int value;
            Node*prev;
            Node*next;

            Node(int k, int v){
                key=k;
                value=v;
                prev=nullptr;
                next=nullptr;
            }
        
    };

    int capacity;
    unordered_map<int, Node*> cache;

    Node*left;
    Node*right;

    LRUCache(int capacity) {
        this->capacity=capacity;

        left=new Node(0,0);
        right=new Node(0,0);

        left->next=right;
        right->prev=left;

    }

    void remove(Node*node){
        Node*prev=node->prev;
        Node*next=node->next;

        prev->next=next;
        next->prev=prev;
    }

    void insert(Node*node){
        Node*next=left->next;
        left->next=node;
        node->prev=left;
        node->next=next;
        next->prev=node;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }

        Node*node=cache[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node *oldNode=cache[key];

            remove(oldNode);
            delete oldNode;

            cache.erase(key);
        }

        Node*node=new Node(key,value);

        cache[key]=node;
        insert(node);

        if(cache.size()>capacity){
            Node* lru = right->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl; // 1

    cache.put(3, 3);              // evicts key 2

    cout << cache.get(2) << endl; // -1

    cache.put(4, 4);              // evicts key 1

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4

    return 0;
}