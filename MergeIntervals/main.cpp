#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals);
bool compareInterval(const Interval& inter1, const Interval& inter2);

int main() {
	int s, e;
	vector<Interval> intervals;
	while (cin >> s >> e) {
		intervals.emplace_back(Interval(s, e));
	}
	vector<Interval> compressed = merge(intervals);
	for (Interval &interval : compressed)
		cout << interval.start << " " << interval.end << endl;
	return 0;
}

vector<Interval> merge(vector<Interval>& intervals) {
	if (intervals.empty())
		return intervals;
	sort(intervals.begin(), intervals.end(), compareInterval);
	vector<Interval> compressed;
	compressed.emplace_back(intervals.front());
	for (unsigned i = 1; i < intervals.size(); ++i) {
		if (intervals[i].start <= compressed.back().end)
			compressed.back().end = max(intervals[i].end, compressed.back().end);
		else
			compressed.emplace_back(intervals[i]);
	}
	return compressed;
}

bool compareInterval(const Interval& inter1, const Interval& inter2) {
	return inter1.start < inter2.start;
}