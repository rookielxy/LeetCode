#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

void nextPermutation(vector<int>& nums);

int main() {
	stringstream ss;
	string str;
	getline(cin, str);
	ss << str;

	vector<int> nums;
	int data;
	while (ss >> data)
		nums.emplace_back(data);
	nextPermutation(nums);
	for (auto ele : nums)
		cout << ele << " ";
	cout << endl;
	return 0;
}

void nextPermutation(vector<int>& nums) {
	if (nums.empty() or nums.size() == 1)
		return;
	if (nums.back() > nums[nums.size() - 2]) {
		swap(nums.back(), nums[nums.size() - 2]);
		return;
	}
	int pivot = (unsigned)nums.size() - 1;
	while (pivot > 0 and nums[pivot] <= nums[pivot - 1])
		--pivot;
	if (pivot == 0) {
		reverse(nums.begin(), nums.end());
		return;
	}
	auto it1 = --nums.end(), it2 = nums.begin() + pivot - 1;
	while (*it1 <= *it2 and it1 > it2)
		--it1;
	assert(it1 != it2);
	swap(*it1, *it2);
	reverse(it2 + 1, nums.end());
}