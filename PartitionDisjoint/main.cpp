#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> parseInput();
int partitionDisjoint(const vector<int>& A);

int main() {
	vector<int> input = parseInput();
	cout << partitionDisjoint(input) << endl;
	return 0;
}

vector<int> parseInput() {
	vector<int> input;
	int ele;
	stringstream ss;
	string str;
	getline(cin, str);
	ss << str;
	while (ss >> ele)
		input.emplace_back(ele);
	return input;
}

int partitionDisjoint(const vector<int>& A) {
	assert(not A.empty());
	vector<int> leftMax(A.size(), INT_MIN), rightMin(A.size(), INT_MAX);

	leftMax[0] = A[0];
	for (int i = 1; i < (int)A.size(); ++i)
		leftMax[i] = max(A[i], leftMax[i - 1]);

	// rightMin.back() = INT_MAX;
	for (int i = (int)A.size() - 2; i >= 0; --i)
		rightMin[i] = min(A[i + 1], rightMin[i + 1]);

	for (int i = 0; i < (int)A.size(); ++i) {
		if (leftMax[i] <= rightMin[i])
			return i + 1;
	}
	assert(false);
	return 0;
}