#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int getMaxRepetitions(const string& s1, int n1, const string& s2, int n2);

int main() {
	string s1, s2;
	int n1, n2;
	cin >> s1 >> n1 >> s2 >> n2;
	cout << getMaxRepetitions(s1, n1, s2, n2) << endl;
	return 0;
}

int getMaxRepetitions(const string& s1, int n1, const string& s2, int n2) {
	assert(not s1.empty());
	assert(not s2.empty());
	assert(n2 > 0);
	if (n1 == 0)
		return 0;

	set<int> s;
	for (char ele : s1)
		s.insert(ele);
	for (char ele : s2) {
		if (s.count(ele) == 0)
			return 0;
	}

	set<int> indexes;
	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] == s2[0])
			indexes.emplace(i);
	}

	map<int, pair<int, int>> hash;
	for (int index : indexes) {
		int rep = 0, p1 = index, p2 = 0;
		while (p2 < s2.size()) {
			if (s2[p2] == s1[p1])
				++p2;
			++p1;
			if (p1 == s1.size()) {
				p1 = 0;
				rep += (p2 == s2.size())? 0 : 1;
			}
		}
		int nextIdx = (indexes.lower_bound(p1) == indexes.end())?
				*indexes.begin() : *indexes.lower_bound(p1);
		hash[index] = make_pair(nextIdx, rep);
	}

	int ans = 0, idx = *indexes.begin();
	int interval = n1 - 1;
	while (true) {
		interval -= hash[idx].second;
		if (hash[idx].first == *indexes.begin())
			--interval;
		if (interval < 0)
			break;
		idx = hash[idx].first;
		++ans;
	}
	return ans/n2;
}