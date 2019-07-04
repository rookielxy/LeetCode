#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> sortArray(vector<int>& nums);
void quickSort(vector<int>& nums, int start, int end);

int main() {
	int data;
	string str;
	stringstream ss;

	getline(cin, str);
	ss << str;

	vector<int> nums;
	while (ss >> data)
		nums.emplace_back(data);
	sortArray(nums);
	for (int ele : nums)
		cout << ele << " ";
	cout << endl;
	return 0;
}

vector<int> sortArray(vector<int>& nums) {
	quickSort(nums, 0, nums.size());
	return nums;
}

void quickSort(vector<int>& nums, int start, int end) {
	if (start == end)
		return;
	int toSwap = start, pivot = nums[start];
	for (int i = start + 1; i < end; ++i) {
		if (nums[i] < pivot) {
			++toSwap;
			swap(nums[i], nums[toSwap]);
		}
	}
	swap(nums[start], nums[toSwap]);
	quickSort(nums, start, toSwap);
	quickSort(nums, toSwap + 1, end);
}