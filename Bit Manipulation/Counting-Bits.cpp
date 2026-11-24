#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

//0 1 10 11 100 101 110 111 1000 1001 1010 1011 1110 1111 10000


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> t(n+1);
        for(int i=1; i<=n; i++){
            t[i]=t[i>>1]+(i&1);
        }
        return t;
    }
};
int main(){

    Solution sol;
    
    for(auto e:sol.countBits(2)){
        cout<<e<<" ";
    }
    cout<<endl;
    for(auto e:sol.countBits(5)){
        cout<<e<<" ";
    }
    cout<<endl;
}