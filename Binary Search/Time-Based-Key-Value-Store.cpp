#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector> 
#include <map>

using namespace std;
//remember the edge cases
class TimeMap {
public:
    map<string, vector<pair<int, string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &search=m[key];
        int start=0;
        int ending=m[key].size()-1;
        while(start<=ending){
            int index=(start+ending)/2;
            if(search[index].first==timestamp){
                return search[index].second;
            }
            else if(search[index].first>timestamp){
                ending=index-1;
            }
            else{
                start=index+1;
            }
        }
        if(ending<0){
            return "";
        }
        return search[ending].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
int main() {
    TimeMap timeMap;
    
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl; // expected: bar
    cout << timeMap.get("foo", 3) << endl; // expected: bar
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << endl; // expected: bar2
    cout << timeMap.get("foo", 5) << endl; // expected: bar2
    
    return 0;
}