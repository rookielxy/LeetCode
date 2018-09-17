#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval);

int main() {
    vector<Interval> intervals;
    string str;
    int s, e;
    while(cin >> s >> e)
        intervals.emplace_back(Interval(s, e));

    Interval newInterval = intervals.back();
    intervals.pop_back();
    vector<Interval> res = insert(intervals, newInterval);
    for(auto ele:res)
        cout << ele.start << " " << ele.end << endl;
    return 0;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    if(intervals.empty()) {
        intervals.emplace_back(newInterval);
        return intervals;
    }

    int s = newInterval.start, e = newInterval.end;
    int sIdx = 0, eIdx = 0;
    for(auto ele: intervals) {
        if(s > ele.start)
            ++sIdx;
        if(s > ele.end)
            ++sIdx;
        if(e >= ele.start)
            ++eIdx;
        if(e > ele.end)
            ++eIdx;
    }

    if(sIdx == eIdx and sIdx%2 == 1)
        return intervals;
    if(sIdx == eIdx and sIdx%2 == 0) {
        intervals.insert(intervals.begin() + sIdx/2, Interval(s, e));
        return intervals;
    }

    s = sIdx%2 == 0? s: intervals[sIdx/2].start;
    e = eIdx%2 == 0? e: intervals[eIdx/2].end;

    vector<Interval> result;
    result.reserve(intervals.size());
    for(int i = 0; i < sIdx/2; ++i)
        result.emplace_back(intervals[i]);
    result.emplace_back(Interval(s, e));
    for(int i = eIdx/2 + eIdx%2; i < intervals.size(); ++i)
        result.emplace_back(intervals[i]);
    return result;
}