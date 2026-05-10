#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

void printV(vector<int> v)
{
    cout << "[";
    for (int i = 0; i < v.size()-1; i++)
    {
        cout << v[i] << ",";
    }
    cout<<v[v.size()-1];
    cout << "]" << endl;
}

int main()
{
    Solution sol;
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 3, 2, 1, 9};
    vector<int> v3 = {9, 9, 9, 9, 9};
    vector<int> s1 = sol.plusOne(v1);
    vector<int> s2 = sol.plusOne(v2);
    vector<int> s3 = sol.plusOne(v3);
    printV(s1);
    printV(s2);
    printV(s3);
}
