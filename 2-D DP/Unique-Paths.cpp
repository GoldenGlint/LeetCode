#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n, 0));
        ans[0][0]=1;

        for(int i=0; i<m; i++){
            for(int l=0; l<n; l++){
                if(i-1>=0){
                    ans[i][l]+=ans[i-1][l];
                }
                if(l-1>=0){
                    ans[i][l]+=ans[i][l-1];
                }
            }
        }

        return ans[m-1][n-1];

    }
};

int main(){
    Solution sol;
    cout<<sol.uniquePaths(3, 7)<<endl;
    cout<<sol.uniquePaths(3, 2)<<endl;
}