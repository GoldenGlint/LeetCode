#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> ans(n, 1);
        for(int i=1; i<m; i++){
            for(int l=1; l<n; l++){
                ans[l]+=ans[l-1];
            }
        }     
        
        return ans[n-1];

    }
};

int main(){
    Solution sol;
    cout<<sol.uniquePaths(3, 7)<<endl;
    cout<<sol.uniquePaths(3, 2)<<endl;
}