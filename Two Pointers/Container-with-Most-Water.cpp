#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ending=height.size()-1;
        int start=0;
        int width=ending-start;
        int fHeight=height[0];
        int sHeight=height[ending];
        int mArea=min(fHeight, sHeight)*width;
        while(start<ending){
            //calc whether new first height is larger
            fHeight=max(fHeight, height[start]);
            sHeight=max(sHeight, height[ending]);
            mArea=max(min(fHeight, sHeight)*width,mArea);
            if(fHeight<=sHeight){
                start++;
            }
            else{
                ending--;
            }

            width--;

           

        }
       
        return mArea;

        
    }
};

int main(){
    Solution sol;
    vector<int> h={1,8,6,2,5,4,8,3,7};
    vector<int> h1={1,1};
    cout<<sol.maxArea(h)<<endl;
    cout<<"Second"<<endl;
    cout<<sol.maxArea(h1)<<endl;
    vector<int> h2={8,7,2,1};
    cout<<"Third"<<endl;
    cout<<sol.maxArea(h2)<<endl;

}