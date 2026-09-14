#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <math.h>

#include <cassert>
using namespace std;

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(right.empty()||num>=right.top()){
            right.push(num);
        }
        else{
            left.push(num);
        }
        if(right.size()>left.size()+1){
            int temp=right.top();
            right.pop();
            left.push(temp);
        }
        else if(left.size()>right.size()){ //left.size()>right.size()
            int temp=left.top();
            right.push(temp);
            left.pop();
        }   
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            float ans= (left.top()+right.top())/2.0;
            return ans;
        }
        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder *medianFinder = new MedianFinder();
    medianFinder->addNum(1);    // arr = [1]
    medianFinder->addNum(2);    // arr = [1, 2]
    cout<<medianFinder->findMedian()<<endl; // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder->addNum(3);    // arr[1, 2, 3]
    cout<<medianFinder->findMedian()<<endl; // return 2.0
}