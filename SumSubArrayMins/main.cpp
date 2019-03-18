#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int sumSubarrayMins(vector<int>& A);

int main() {
	string str;
	stringstream ss;
	int data;
	vector<int> A;

	getline(cin, str);
	ss << str;
	while (ss >> data)
		A.emplace_back(data);
	cout << sumSubarrayMins(A) << endl;
	return 0;
}

int sumSubarrayMins(vector<int>& A) {
	if (A.empty())
		return 0;
	vector<int> right(A.size(), (int)A.size());
	vector<int> left(A.size(), -1);

	for (int i = 1; i < A.size(); ++i) {
		int toComp = i - 1;
		while (toComp != -1 and A[i] <= A[toComp])
			toComp = left[toComp];
		left[i] = toComp;
	}

	for (int i = (int)A.size() - 1; i >= 0; --i) {
		int toComp = i + 1;
		while (toComp != (int)A.size() and A[i] < A[toComp])
			toComp = right[toComp];
		right[i] = toComp;
	}

	int ret = 0;
	const int MOD = (int)1e9 + 7;
	for (int i = 0; i < A.size(); ++i)
		ret = (ret + (A[i]*(i - left[i])*(right[i] - i))%MOD)%MOD;
	return ret;
}