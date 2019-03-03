#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int longestOnes(vector<int>& A, int K);
int dfs(vector<int> intervals, int K);

int main() {
	stringstream ss;
	string str;
	vector<int> A;
	int binary;
	int K;

	getline(cin, str);
	ss << str;
	while (ss >> binary)
		A.emplace_back(binary);
	cin >> K;
	cout << longestOnes(A, K) << endl;
	return 0;
}

int longestOnes(vector<int>& A, int K) {
	if (A.empty())
		return 0;
	vector<int> intervals;
	int count = 0;
	int data = 1;
	for (int ele : A) {
		if (ele == data) {
			++count;
		} else {
			intervals.emplace_back(count);
			count = 1;
			data = ele;
		}
	}
	if (count != 0) {
		intervals.emplace_back(count);
		if (A.back() == 0)
			intervals.emplace_back(0);
	}

	return dfs(intervals, K);
}

int dfs(vector<int> intervals, int K) {
	bool less = false;
	for (int i = 0; 2*i + 1 < intervals.size(); ++i) {
		if (intervals[2*i + 1] <= K)
			less = true;
	}
	if (not less) {
		int peak = 0;
		for (int i = 0; 2*i < intervals.size(); ++i)
			peak = max(peak, intervals[2*i]);
		return peak + K;
	}
	int peak = 0;
	for (int idx = 1; idx < intervals.size(); idx += 2) {
		if (intervals[idx] == K) {
			peak = max(peak, intervals[idx] + intervals[idx - 1] + intervals[idx + 1]);
		} else if (intervals[idx] < K) {
			vector<int> merge_interval(intervals.size() - 2);
			for (int i = 0, j = 0; i < intervals.size(); ++i, ++j) {
				if (i == idx - 1) {
					merge_interval[j] = intervals[idx - 1] + intervals[idx] + intervals[idx + 1];
					i += 2;
				} else {
					merge_interval[j] = intervals[i];
				}
			}
			peak = max(peak, dfs(merge_interval, K - intervals[idx]));
		}
	}
	return peak;
}