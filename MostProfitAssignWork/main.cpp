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
		jobs[i].first = difficulty[i];
		jobs[i].second = profit[i];
	}
	sort(jobs.begin(), jobs.end());

	map<int, int> diff2prof;
	int maxProfit = 0;
	for (auto p : jobs) {
		maxProfit = max(maxProfit, p.second);
		diff2prof[p.first] = maxProfit;
	}

	int sumProfit = 0;
	for (auto ele : worker) {
		auto it = diff2prof.upper_bound(ele);
		if (it == diff2prof.begin())
			continue;
		--it;
		sumProfit += it->second;
	}
	return sumProfit;
}