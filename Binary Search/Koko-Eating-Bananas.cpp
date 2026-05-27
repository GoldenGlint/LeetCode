#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solve(vector<int> &piles, int k){
    int sum=0;
    for(int i=0; i<piles.size(); i++){
        sum += (piles[i] + k - 1) / k;
    }
    return sum;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int ending=piles[0];
        for(int i=0; i<piles.size(); i++){
            ending=max(ending, piles[i]);
        }
        int index=(start+ending)/2;
        while(start<ending){
            index=(start+ending)/2;
            if(solve(piles,index)<=h){
                ending=index;

            }
            else{
                start=index+1;
            }
        }
        return start;
    }
};

int main(){
    Solution sol;
    vector<int> p1 = {3, 6, 7, 11};
    vector<int> p2 = {30, 11, 23, 4, 20};
    vector<int> p3 = {30, 11, 23, 4, 20};

    cout << sol.minEatingSpeed(p1, 8) << endl;  // 4
    cout << sol.minEatingSpeed(p2, 5) << endl;  // 30
    cout << sol.minEatingSpeed(p3, 6) << endl;  // 23
}