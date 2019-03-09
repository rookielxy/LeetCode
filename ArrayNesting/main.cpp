#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int arrayNesting(vector<int>& nums);
void dfs(vector<int>& nums, vector<int>& length, int idx);

int main() {
	stringstream ss;
	string str;
	int data;
	vector<int> nums;

	getline(cin, str);
	ss << str;
	while (ss >> data)
		nums.emplace_back(data);
	cout << arrayNesting(nums) << endl;
	return 0;
}

int arrayNesting(vector<int>& nums) {
	vector<int> length(nums.size(), -1);
	for (int i = 0; i < nums.size(); ++i)
		dfs(nums, length, i);
	int maxLength = 0;
	for (int ele : length)
		maxLength = max(maxLength, ele);
	return maxLength;
}

void dfs(vector<int>& nums, vector<int>& length, int idx) {
	if (length[idx] != -1)
		return;
	int ptr = idx, count = 0;
	unordered_map<int, bool> visited;
	while (not visited[ptr]) {
		++count;
		visited[ptr] = true;
		ptr = nums[ptr];
	}
	if (ptr != idx) {
		while (idx != ptr) {
			length[idx] = count--;
			idx = nums[idx];
		}
	}
	while (true) {
		length[ptr] = count;
		ptr = nums[ptr];
		if (ptr == idx)
			break;
	}
}