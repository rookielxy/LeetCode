#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <functional>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x);


int main() {
	string str;
	stringstream ss;
	int x, k, temp;
	vector<int> arr;

	getline(cin, str);
	ss << str;
	while (ss >> temp)
		arr.emplace_back(temp);
	cin >> k >> x;
	for (int ele : findClosestElements(arr, k, x))
		cout << ele << " ";
	cout << endl;
	return 0;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
	if (arr.size() <= k)
		return arr;
	int p = 0, q = arr.size(), middle = p + (q - p)/2;
	while (p < middle) {
		if (abs(arr[p] - x) < abs(arr[q - 1] - x))
			q = middle;
		else
			p = middle;
		middle = p + (q - p)/2;
	}
	int left = max(p - k, 0), right = min(p + k, (int)arr.size());
	while (right - left > k) {
		if (x - arr[left] <= arr[right - 1] - x)
			--right;
		else
			++left;
	}
	return vector<int>(arr.begin() + left, arr.begin() + right);
}