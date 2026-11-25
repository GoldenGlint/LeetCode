#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

#include <cassert>
using namespace std;

//new num is num*10+digit
//num*10+digit<=INT_MAX
//num*10+digit>=INT_MIN


class Solution {
public:
    int reverse(int x) {
        int num=0;
        while(x!=0){
            int digit=x%10;
            x/=10;
            if(num>INT_MAX/10||(num==INT_MAX/10&&digit>7)){
                return 0;
            }
            if(num<INT_MIN/10||(num==INT_MIN/10&&digit<-8)){
                return 0;
            }
            num=num*10+digit;
        }
        return num;
    }
};
int main(){

    Solution sol;

    int x=123;
    int y=-123;
    cout<<sol.reverse(x)<<endl;
    cout<<sol.reverse(y)<<endl;
}