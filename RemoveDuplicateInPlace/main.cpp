#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> parseInput();
int removeDuplicates(vector<int>& nums);

int main() {
	vector<int> nums = parseInput();
	cout << removeDuplicates(nums) << endl;
	for (int ele : nums)
		cout << ele << " ";
	cout << endl;
	return 0;
}

vector<int> parseInput() {
	string str;
	getline(cin, str);

	stringstream ss;
	ss << str;

	vector<int> nums;
	int ele;
	while (ss >> ele)
		nums.emplace_back(ele);
	return nums;
}

int removeDuplicates(vector<int>& nums) {
	if (nums.empty())
		return 0;
	int p = 0, q = 0;
	while (q < nums.size()) {
		int nextq = q;
		while (nextq < nums.size() and nums[nextq] == nums[q])
			++nextq;
		q = max(nextq - 2, q);
		while (q < nextq) {
			nums[p] = nums[q];
			++q;
			++p;
		}
	}
	return p;
}