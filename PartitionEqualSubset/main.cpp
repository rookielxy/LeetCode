#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

bool canPartition(vector<int>& nums);

int main() {
	stringstream ss;
	string str;
	int data;
	vector<int> nums;

	getline(cin, str);
	ss << str;
	while (ss >> data)
		nums.emplace_back(data);
	if (canPartition(nums))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}

bool canPartition(vector<int>& nums) {
	int sum = 0;
	for (int ele : nums)
		sum += ele;

	if (sum%2 == 1)
		return false;
	for (int ele : nums) {
		if (ele > sum/2)
			return false;
	}

	bitset<10000> bits(1);
	for (int ele : nums) {
		bits |= bits << ele;
		if (bits[sum/2])
			return true;
	}
	return false;
}