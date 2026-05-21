#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int left=0;
        int right=height.size()-1;
        int maxLeft=0;
        int maxRight=0;
        while(left<right){
            cout << "l=" << left << " r=" << right 
         << " ml=" << maxLeft << " mr=" << maxRight 
         << " w=" << water << endl;
            if(height[left]<height[right]){
                if(height[left]>=maxLeft){
                    maxLeft=height[left];
                }
                else{
                    water+=maxLeft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=maxRight){
                    maxRight=height[right];
                }
                else{
                    water+=maxRight-height[right];
                }
                right--;
            }
        }
        return water;
    }
};

int main(){
    Solution sol;
    vector<int> w1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<sol.trap(w1)<<endl;
}