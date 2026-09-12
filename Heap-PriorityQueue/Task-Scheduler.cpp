#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

class Solution {
public:
void printMap(unordered_map<char, int> freq){
    for(auto it=freq.begin(); it!=freq.end(); it++){
            cout<<it->first<<":"<< it->second<<" ";
    }
    cout<<endl;
}
struct compare{
    bool operator()(pair<char, int> a, pair<char, int> b){
        return a.second<b.second;
    };
};
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(int i=0; i<tasks.size(); i++){
            freq[tasks[i]]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
        queue<pair<pair<char,int>, int>> cooldown;
        for(auto it=freq.begin(); it!=freq.end(); it++){
            pq.push({it->first, it->second});
        }
        
        int ans=0;

        while(!pq.empty()||!cooldown.empty()){
            if(!cooldown.empty() && cooldown.front().second<=ans){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
            if(!pq.empty()){
                pair<char, int> temp=pq.top();
                cout<<temp.first<<" "<<temp.second<<endl;
                pq.pop();
                if(temp.second-1!=0){
                cooldown.push({{temp.first, temp.second-1}, ans+n+1});
            }
            }

            ans++;
            
            
        }
        return ans;
    }
};

int main(){
    
    Solution sol;
    vector<char> tasks1={'A', 'A', 'A', 'B', 'B', 'B'};
    vector<char> tasks2={'A', 'C', 'A', 'B', 'D', 'B'};
    vector<char> tasks3={'A', 'A', 'A', 'B', 'B', 'B'};
    cout<<sol.leastInterval(tasks1, 2)<<endl;
    cout<<endl;
    cout<<sol.leastInterval(tasks2, 1)<<endl;
    cout<<endl;
    cout<<sol.leastInterval(tasks3, 3)<<endl;
    cout<<endl;
}