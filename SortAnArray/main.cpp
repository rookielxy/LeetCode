#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> sortArray(vector<int>& nums);

void quickSort(vector<int>& nums);
void quickSort(vector<int>& nums, int start, int end);

void heapSort(vector<int>& nums);
void constructHeap(vector<int>& nums);
void constructHeap(vector<int>& nums, int start);
void fixHeap(vector<int>& nums, int start, int end);


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
	// quickSort(nums);
	heapSort(nums);
	return nums;
}

void quickSort(vector<int>& nums) {
	quickSort(nums, 0, (int)nums.size());
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

void heapSort(vector<int>& nums) {
	constructHeap(nums);
	for (int i = (int)nums.size() - 1; i >= 0; --i) {
		swap(nums[i], nums[0]);
		fixHeap(nums, 0, i);
	}
}

void constructHeap(vector<int>& nums) {
	constructHeap(nums, 0);
}

void constructHeap(vector<int>& nums, int start) {
	int left = 2*start + 1, right = 2*start + 2;
	if (left >= (int)nums.size() or right >= (int)nums.size())
		return;
	constructHeap(nums, left);
	constructHeap(nums, right);
	fixHeap(nums, start, (int)nums.size());
}

void fixHeap(vector<int>& nums, int start, int end) {
	/**
	 * precondition: two sub-heap partial-ordered
	 */
	int left = 2*start + 1, right = 2*start + 2;
	if (left >= end and right >= end)
		return;
	if (left == end - 1) {
		if (nums[start] < nums[left])
			swap(nums[start], nums[left]);
		return;
	}

	int toSwap = (nums[left] < nums[right])? right : left;
	if (nums[start] < nums[toSwap]) {
		swap(nums[start], nums[toSwap]);
		fixHeap(nums, toSwap, end);
	}
}
