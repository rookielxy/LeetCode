#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int>& A, int K);

int main() {
	int data, k;
	string str;
	stringstream ss;
	vector<int> input;

	getline(cin, str);
	ss << str;
	while (ss >> data)
		input.emplace_back(data);
	cin >> k;
	auto ret = kthSmallestPrimeFraction(input, k);
	assert(ret.size() == 2);
	cout << ret[0] << " / " << ret[1] << endl;
	return 0;
}

vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
	sort(A.begin(), A.end());
	struct Compare {
		const vector<int>& matrix;

		explicit Compare(const vector<int>& A): matrix(A) {}

		bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
			return matrix[p1.first]*matrix[p2.second] > matrix[p2.first]*matrix[p1.second];
		}
	};
	Compare compare(A);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap(compare);

	for (int i = 0; i < (int)A.size(); ++i)
		heap.emplace(make_pair(0, i));

	pair<int, int> result;
	for (int i = 0; i < K; ++i) {
		result = heap.top();
		heap.pop();
		if (result.first == result.second - 1)
			continue;
		else
			heap.emplace(make_pair(result.first + 1, result.second));
	}
	return vector<int>{A[result.first], A[result.second]};
}