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

	vector<int> index(s2.size() + 1);
	vector<int> count(s2.size() + 1);
	map<int, int> hash;
	int idx = 0, cnt = 0;

	index[0] = count[0] = 0;
	hash.emplace(0, 0);
	for (int i = 1; i <= min(n1, (int)s2.size()); ++i) {
		for (char ch : s1) {
			if (ch == s2[idx]) {
				++idx;
				if (idx == s2.size()) {
					idx = 0;
					++cnt;
				}
			}
		}
		index[i] = idx;
		count[i] = cnt;
		if (hash.find(idx) == hash.end())
			hash.emplace(idx, i);
		else {
			int cnt1 = count[hash[idx]];
			int pattern = (cnt - cnt1)*((n1 - hash[idx])/(i - hash[idx]));
			int cnt2 = count[hash[idx] + (n1 - hash[idx])%(i - hash[idx])] - cnt1;
			return (cnt1 + pattern + cnt2)/n2;
		}
	}
	return count[n1]/n2;
}