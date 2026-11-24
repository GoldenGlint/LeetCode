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
        int num=0;
        for(int i=31; i>=0; i--){//what am I doing here bro
            int temp=1;
            temp=temp<<i;
            int bit=temp&n;
            bit=bit>>i;
            bit=bit<<(31-i);
            num=num|bit;
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