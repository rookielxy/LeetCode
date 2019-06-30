#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> prevPermOpt1(vector<int>& A);
bool isLeastPermutation(vector<int>& A);

int main() {
	vector<int> nums;
	stringstream ss;
	string str;
	int integer;

	getline(cin, str);
	ss << str;
	while (ss >> integer)
		nums.emplace_back(integer);
	for (int ele : prevPermOpt1(nums))
		cout << ele << " ";
	cout << endl;
	return 0;
}

vector<int> prevPermOpt1(vector<int>& A) {
	if (isLeastPermutation(A))
		return A;
	map<int, int> m;
	for (int i = (int)A.size() - 1; i >= 0; --i) {
		auto it = m.lower_bound(A[i]);
		if (it != m.begin()) {
			--it;
			swap(A[i], A[it->second]);
			return A;
		}
		m[A[i]] = i;
	}
	return A;
}

bool isLeastPermutation(vector<int>& A) {
	for (int i = 0; i < (int)A.size() - 1; ++i) {
		if (A[i] > A[i + 1])
			return false;
	}
	return true;
}