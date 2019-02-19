#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

int minKBitFlips(vector<int>& A, int K);

int main() {
	stringstream ss;
	string str;
	vector<int> data;
	int temp, k;

	getline(cin, str);
	ss << str;
	while (ss >> temp)
		data.emplace_back(temp);
	cin >> k;
	cout << minKBitFlips(data, k) << endl;
	return 0;
}

int minKBitFlips(vector<int>& A, int K) {
	assert(not A.empty());
	queue<int> flips;
	int count = 0;
	/*
	 * loop invariants:
	 *      i <= flips.front()
	 * then flips records every flip that flips bit A[i],
	 * we can determine to flip A[i] again or not.
	 * */
	for (int i = 0; i < A.size(); ++i) {
		if (not flips.empty() and i > flips.front())
			flips.pop();
		if (A[i] == flips.size()%2) {
			flips.push(i + K - 1);
			++count;
		}
	}
	return (flips.empty() or flips.back() < A.size())? count : -1;
}