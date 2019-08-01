#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

bool checkValidString(const string& s);

int main() {
	string str;
	cin >> str;
	if (checkValidString(str))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}

bool checkValidString(const string& s) {
	if (s.empty())
		return true;
	vector<pair<int, int>> bound(s.size() + 1);
	bound[0].first = bound[0].second = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		int uppDelta = 0, lowDelta = 0;
		switch (s[i]) {
			case '(': uppDelta = lowDelta = 1; break;
			case ')': uppDelta = lowDelta = -1; break;
			case '*': uppDelta = 1; lowDelta = -1; break;
			default: assert(false);
		}
		bound[i + 1].first = bound[i].first + uppDelta;
		bound[i + 1].second = max(0, bound[i].second + lowDelta);
		if (bound[i + 1].first < 0)
			return false;
	}
	return bound.back().second == 0;
}

