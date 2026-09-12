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
        
        priority_queue<int> pq;
        queue<pair<int, int>> cooldown;

        int time=0; 
        
        for(auto [task, count] : freq){
            pq.push(count);
        }

        while(!pq.empty() || !cooldown.empty()){
            if(pq.empty()){
                time=cooldown.front().second;
            }
            if(!cooldown.empty()&&cooldown.front().second<=time){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
            if(!pq.empty()){
                int count=pq.top();
                pq.pop();
                count--;
                if(count>0){
                    cooldown.push({count, time+n+1});
                }
            }
            time++;
        }

        return time;
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