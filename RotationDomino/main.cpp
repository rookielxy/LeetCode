#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int minDominoRotations(vector<int>& A, vector<int>& B);

int main() {
	stringstream ss;
	string str;
	int data;
	vector<int> A;
	vector<int> B;

	getline(cin, str);
	ss << str;
	while (ss >> data)
		A.emplace_back(data);
	getline(cin, str);
	ss.clear();
	ss << str;
	while (ss >> data)
		B.emplace_back(data);
	cout << minDominoRotations(A, B) << endl;
	return 0;
}

int minDominoRotations(vector<int>& A, vector<int>& B) {
	assert(A.size() == B.size());
	assert(not A.empty());
	unordered_map<int, pair<int, int>> cnt;
	unordered_map<int, int> duplicate;
	for (int ele : A)
		++cnt[ele].first;
	for (int ele : B)
		++cnt[ele].second;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == B[i])
			++duplicate[A[i]];
	}
	bool valid = false;
	int minRotate = INT_MAX;
	for (int i = 1; i <= 6; ++i) {
		if (cnt[i].first + cnt[i].second - duplicate[i] >= A.size()) {
			valid = true;
			minRotate = min(minRotate, (int)A.size() - max(cnt[i].first, cnt[i].second));
		}
	}
	if (not valid)
		return -1;
	return minRotate;
}