#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs);
int mincostTickets(vector<int>::iterator begin, vector<int>::iterator end, vector<int>& costs);

int main() {
	stringstream ss;
	string str;
	int temp;
	vector<int> days;
	vector<int> costs;

	getline(cin, str);
	ss << str;
	while (ss >> temp)
		days.emplace_back(temp);
	for (int i = 0; i < 3; ++i) {
		cin >> temp;
		costs.emplace_back(temp);
	}
	cout << mincostTickets(days, costs) << endl;
	return 0;
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
	if (days.empty())
		return 0;
	int *array = new int[days.size()];
	array[0] = costs[0];

	int pweek = 0, pmonth = 0;
	for (int i = 1; i < days.size(); ++i) {
		int solution1 = array[i - 1] + costs[0];
		int solution2, solution3;

		if (days[i] - days.front() < 7) {
			solution2 = costs[1];
		} else {
			while (days[i] - days[pweek] >= 7)
				++pweek;
			solution2 = costs[1] + array[--pweek];
		}

		if (days[i] - days.front() < 30) {
			solution3 = costs[2];
		} else {
			while (days[i] - days[pmonth] >= 30)
				++pmonth;
			solution3 = costs[2] + array[--pmonth];
		}

		array[i] = min(solution1, min(solution2, solution3));
	}
	return array[days.size() - 1];
}

/*
int mincostTickets(vector<int>& days, vector<int>& costs) {
	if (days.empty())
		return 0;
	return mincostTickets(days.begin(), days.end(), costs);
}

int mincostTickets(vector<int>::iterator begin, vector<int>::iterator end, vector<int>& costs) {
	if (begin == end)
		return 0;
	int firstDay = *begin;

	++begin;
	int solution1 = costs[0] + mincostTickets(begin, end, costs);

	while (begin != end and *begin - firstDay < 7)
		++begin;
	int solution2 = costs[1] + mincostTickets(begin, end, costs);

	while (begin != end and *begin - firstDay < 30)
		++begin;
	int solution3 = costs[2] + mincostTickets(begin, end, costs);

	return min(solution1, min(solution2, solution3));
}
*/