#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> grayCode(int n);

int main() {
	int n;
	cin >> n;
	for (auto &ele : grayCode(n))
		cout << ele << endl;
	return 0;
}

vector<int> grayCode(int n) {
	vector<int> result;
	if (n == 0) {
		result.emplace_back(0);
	} else {
		vector<int> lower = grayCode(n - 1);
		result.insert(result.end(), lower.begin(), lower.end());
		reverse(lower.begin(), lower.end());
		for (auto &ele : lower)
			ele += (int)pow(2, n - 1);
		result.insert(result.end(), lower.begin(), lower.end());
	}
	return result;
}