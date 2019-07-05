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
	struct compare {
		bool operator() (pair<int, int> p1, pair<int, int> p2) {
			return p1.first*p2.second < p2.first*p1.second;
		}
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;

	for (int i = 0; i < (int)A.size(); ++i) {
		int numerator = A[i];
		for (int j = i + 1; j < (int)A.size(); ++j) {
			int denominator = A[j];
			heap.push(make_pair(numerator, denominator));
			if (heap.size() > K)
				heap.pop();
		}
	}
	return vector<int>{heap.top().first, heap.top().second};
}