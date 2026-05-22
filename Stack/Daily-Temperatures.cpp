#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> indices;
        vector<int> days(n, 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!indices.empty() && temperatures[i] > temperatures[indices.top()])
            {
                int prev = indices.top();
                indices.pop();
                days[prev] = i - prev;
            }
            indices.push(i);
        }
        return days;
    }
};

void test(vector<int> temperatures, vector<int> expected)
{
    Solution sol;
    vector<int> output = sol.dailyTemperatures(temperatures);

    cout << "Output:   [";
    for (int i = 0; i < output.size(); i++)
        cout << output[i] << (i + 1 < output.size() ? "," : "");
    cout << "]\n";

    cout << "Expected: [";
    for (int i = 0; i < expected.size(); i++)
        cout << expected[i] << (i + 1 < expected.size() ? "," : "");
    cout << "]\n";

    cout << (output == expected ? "PASS" : "FAIL") << "\n\n";
}

int main()
{
    test({73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0});
    test({30, 40, 50, 60}, {1, 1, 1, 0});
    test({30, 60, 90}, {1, 1, 0});

    return 0;
}