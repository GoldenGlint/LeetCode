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
    int getSum(int a, int b) {
        while(b!=0){
            int carry=(a&b)<<1;
            a=a^b;
            b=carry;
        }
        return a;
    }
};


int main(){

    Solution sol;
    int a=1, b=2;
    int a1=2, b1=3;
    cout<<sol.getSum(a, b)<<endl;
    cout<<sol.getSum(a1, b1)<<endl;
}