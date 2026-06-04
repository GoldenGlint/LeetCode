#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector> 

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m=nums1.size();
        int n=nums2.size();
        int lo=0, hi=m;
        while(lo<=hi){
            int px=(lo+hi)/2;
            int py=(m+n+1)/2-px;

            int maxL1=(px==0)? INT_MIN : nums1[px-1];
            int minR1=(px==m)? INT_MAX : nums1[px];
            int maxL2=(py==0)? INT_MIN : nums2[py-1];
            int minR2=(py==n)? INT_MAX : nums2[py];

            if(maxL1<=minR2 &&maxL2<=minR1){
                if((m+n)%2==1){
                    return max(maxL1, maxL2);
                }
                else{
                    return (max(maxL1, maxL2) + min(minR1, minR2)) / 2.0;
                }
            }
            else if(maxL1>minR2){
                hi=px-1;
            }
            else{
                lo=px+1;
            }
            
        }
        return 0.0;
    }
};

int main(){
    Solution sol;
    vector<int> n1={1,2};
    vector<int> n2={3};

    vector<int> n3={1,2};
    vector<int> n4={3,3};
    cout<<sol.findMedianSortedArrays(n1,n2)<<endl;
    cout<<sol.findMedianSortedArrays(n3,n4)<<endl;
}