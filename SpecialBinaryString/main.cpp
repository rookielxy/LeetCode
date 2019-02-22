#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string makeLargestSpecial(string S);

int main() {
	string str;
	cin >> str;
	cout << makeLargestSpecial(str) << endl;
	return 0;
}

string makeLargestSpecial(string S) {
	if (S.empty() or S.size() == 2)
		return S;
	assert(S.size()%2 == 0);
	int cnt = 0, equalZero = 0;
	for (int i = 0; i < S.size(); ++i) {
		cnt = (S[i] == '0')? cnt - 1 : cnt + 1;
		if (cnt == S.size()/2)
			return S;
		if (cnt == 0)
			++equalZero;
	}
	if (equalZero == 1)
		return "1" + makeLargestSpecial(S.substr(1, S.size() - 2)) + "0";
	vector<string> strs;
	unsigned last = 0;
	for (unsigned i = 0; i < S.size(); ++i) {
		cnt = (S[i] == '0')? cnt - 1 : cnt + 1;
		if (cnt == 0) {
			strs.emplace_back(makeLargestSpecial(S.substr(last, i - last + 1)));
			last = i + 1;
		}
	}
	sort(strs.begin(), strs.end());
	reverse(strs.begin(), strs.end());
	for (unsigned i = 1; i < strs.size(); ++i)
		strs[0] += strs[i];
	return strs[0];
}