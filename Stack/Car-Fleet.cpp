#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i=0; i<position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        /*for(auto [first,second]:cars){
            cout<<"position: "<<first<<" speed: "<<second<<" ";
        }*/
        cout<<endl;
        stack<float> ovr;
        for(int i=0; i<cars.size(); i++){
            float time=(float)(target-cars[i].first)/cars[i].second;
            if(ovr.empty()){
                ovr.push(time);
            }
            else{
                if(time>ovr.top()){
                    ovr.push(time);
                }
            }
        }
        return ovr.size();

    }
};

int main() {
    // Example 1
    Solution sol;
    int target1 = 12;
    vector<int> pos1 = {10, 8, 0, 5, 3};
    vector<int> spd1 = {2, 4, 1, 1, 3};
    cout << "Example 1 Output: " << sol.carFleet(target1, pos1, spd1) << endl; // 3

    // Example 2
    int target2 = 10;
    vector<int> pos2 = {3};
    vector<int> spd2 = {3};
    cout << "Example 2 Output: " << sol.carFleet(target2, pos2, spd2) << endl; // 1

    // Example 3
    int target3 = 100;
    vector<int> pos3 = {0, 2, 4};
    vector<int> spd3 = {4, 2, 1};
    cout << "Example 3 Output: " << sol.carFleet(target3, pos3, spd3) << endl; // 1

    return 0;
}