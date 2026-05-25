#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int width=matrix[0].size();
        int start=0;
        int end=n*width-1;
        while(start<=end){
            int index=(start+end)/2;
            int first=index/width;
            int second=index%width;
            if(matrix[first][second]==target){
                return true;
            }
            else if(matrix[first][second]<target){
                start=index+1;
            }
            else{
                end=index-1;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> m1={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<sol.searchMatrix(m1,3)<<endl;
    cout<<sol.searchMatrix(m1,13)<<endl;
}