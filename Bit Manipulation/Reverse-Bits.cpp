#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;
// 25, 1 >>i <<31-i
class Solution {
public:
    int reverseBits(int n) {
        unsigned int num=0;
        unsigned int x=n;
        for(int i=31; i>=0; i--){//what am I doing here bro
            unsigned int bit=0;
            bit=(x>>i)&1;
            num|=bit<<(31-i);
        }
        return num;
    }
};
int main(){

    Solution sol;
    int n = 43261596;
    cout<<sol.reverseBits(n)<<endl;
    int n1 = 2147483644;
    cout<<sol.reverseBits(n1)<<endl;
}