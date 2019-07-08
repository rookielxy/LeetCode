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

/**
 * 使用优先级队列，迭代K次，
 * 假定数组有序条件下且K >> A.length，最坏时间复杂度为O(K*log K)。
 */
/*
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
 */

/**
 * 二分搜索，直到找到阈值middle使小于middle的分数刚好为K个，
 * 最坏时间复杂度为O(A.length*log K)
 */
vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
	sort(A.begin(), A.end());
	double start = 0.0, end = 1.0;

	while (start < end) {
		double middle = start + (end - start)/2;
		int numeIdx = 0, counter = 0, i = 0;
		int col = 0, row = (int)A.size() - 1;   // 记录counter个小于middle的数中最大值
		for (i = 0; i < (int)A.size(); ++i) {
			while (true) {
				if (numeIdx == i or (double)A[numeIdx]/A[i] > middle) {
					if (numeIdx > 0 and A[numeIdx - 1]*A[row] > A[col]*A[i]) {
						col = numeIdx - 1;
						row = i;
					}
					counter += numeIdx;
					break;
				}
				++numeIdx;
			}

			if (counter > K)
				break;
		}
		if (counter > K)
			end = middle;
		else if (counter == K)
			return vector<int>{A[col], A[row]};
		else
			start = middle;
	}
	// meaningless return to make compiler happy
	return vector<int>{0, 0};
}