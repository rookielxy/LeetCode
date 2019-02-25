#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int numSubarraysWithSum(vector<int>& A, int S);

int main() {
	stringstream ss;
	string str;
	int data, S;
	vector<int> nums;

	getline(cin, str);
	ss << str;
	while (ss >> data)
		nums.emplace_back(data);
	cin >> S;
	cout << numSubarraysWithSum(nums, S) << endl;
	return 0;
}

int numSubarraysWithSum(vector<int>& A, int S) {
	if (A.empty())
		return 0;
	if (S == 0) {
		int ans = 0, idx = 0, length = 0;
		while (idx < A.size()) {
			if (A[idx] == 0)
				++length;
			else {
				ans += (length + 1)*length/2;
				length = 0;
			}
			++idx;
		}
		ans += (length + 1)*length/2;
		return ans;
	}
	vector<int> ones;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == 1)
			ones.emplace_back(i);
	}
	if (ones.size() < S)
		return 0;
	int ans = 0;
	for (int i = 0; i + S - 1 < ones.size(); ++i) {
		int times = (i > 0)? ones[i] - ones[i - 1] : ones[i] + 1;
		if (i + S - 1 == ones.size() - 1)
			ans += times*(A.size() - ones.back());
		else if (i + S - 1 < ones.size() - 1)
			ans += times*(ones[i + S] - ones[i + S - 1]);
	}
	return ans;
}