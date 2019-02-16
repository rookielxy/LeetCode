#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool canJump(vector<int>& nums);

int main() {
	stringstream ss;
	string str;
	getline(cin, str);
	ss << str;

	int data;
	vector<int> nums;
	while (ss >> data)
		nums.emplace_back(data);
	if (canJump(nums))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}

bool canJump(vector<int>& nums) {
	if (nums.empty() or nums.size() == 1)
		return true;
	if (nums[0] == 0)
		return false;
	bool zero = false;
	for (int ele : nums)
		zero = zero || (ele == 0);
	if (not zero)
		return true;

	int leftmost = (unsigned)nums.size() - 1;
	for (int i = (unsigned)nums.size() - 2; i >= 0; --i) {
		if (nums[i] + i >= leftmost)
			leftmost = i;
	}
	return leftmost == 0;
}