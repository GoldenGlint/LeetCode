#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include <cassert>
using namespace std;

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b)
             {
                 if (a.start != b.start)
                 {
                     return a.start < b.start;
                 }
                 else
                 {
                     return a.end < b.end;
                 }
             });
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i - 1].end)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<Interval> interval1 = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
    vector<Interval> interval2 = {Interval(5, 8), Interval(9, 15)};
    cout << sol.canAttendMeetings(interval1) << endl;
    cout << sol.canAttendMeetings(interval2) << endl;
}
