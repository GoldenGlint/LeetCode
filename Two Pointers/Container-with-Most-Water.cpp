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
            fHeight=max(fHeight, height[start+1]);
            int h=min(fHeight,sHeight); //which one to use
            mArea=max(mArea, (width-1)*h);//new width is -1
            
            sHeight=max(sHeight, height[ending-1]);
            h=min(fHeight,sHeight);
            mArea=max(mArea, (width-1)*h);
            
            start++;
            ending--;
            width=width-2;

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