#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker);

int main() {
	int data;
	string str;
	stringstream ss;

	vector<vector<int>> input(3, vector<int>());
	for (int i = 0; i < 3; ++i) {
		getline(cin, str);
		ss << str;
		while (ss >> data)
			input[i].emplace_back(data);
		ss.clear();
	}
	cout << maxProfitAssignment(input[0], input[1], input[2]) << endl;
	return 0;
}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
	vector<pair<int, int>> jobs(difficulty.size());
	for (int i = 0; i < (int)jobs.size(); ++i) {
		jobs[i].first = profit[i];
		jobs[i].second = difficulty[i];
	}
	sort(jobs.begin(), jobs.end(),
			[](pair<int, int> p1, pair<int, int> p2) -> bool { return p1.first > p2.first; });
	sort(worker.begin(), worker.end(),
			[](int i1, int i2) -> bool { return i1 > i2; });

	int sumProfit = 0, idx = 0;
	for (auto ele : worker) {
		while (idx < jobs.size() and jobs[idx].second > ele)
			++idx;
		if (idx < jobs.size())
			sumProfit += jobs[idx].first;
	}
	return sumProfit;
}