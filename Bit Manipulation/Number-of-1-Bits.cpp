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
    int hammingWeight(int n) {
        int count=0;
        while(n){
            n &=(n-1);
            count++;
        }
        return count;
    }
};
int main(){

    Solution sol;
    
    cout<<sol.hammingWeight(11)<<endl;
    cout<<sol.hammingWeight(128)<<endl;
}