#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        int maxHeight=0;
        int n=heights.size();
        for(int i=0; i<=n; i++){
            int cur=(i==n) ? 0 : heights[i];
            while(!st.empty()&&heights[st.top()]>=cur){
                int height=heights[st.top()];
                st.pop();
                int width=st.empty()? i : i-st.top()-1;
                maxHeight=max(maxHeight, height*width);
            }
            st.push(i);
        }
        return maxHeight;
    }
};

int main(){
    Solution sol;
    vector <int> s1={2,1,5,6,2,3};
    vector <int> s2={2,4};
    cout<<sol.largestRectangleArea(s1)<<endl;
    cout<<sol.largestRectangleArea(s2)<<endl;

}