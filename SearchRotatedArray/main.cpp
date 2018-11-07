#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target);

int main() {
	vector<int> nums;
	int data, target;
	cin >> target;
	while (cin >> data)
		nums.emplace_back(data);
	int idx = search(nums, target);
	cout << idx << endl;
	return 0;
}

int search(vector<int>& nums, int target) {
	if (nums.empty())
		return -1;
	if (nums.size() == 1)
		return target == nums[0]? 0 : -1;
	int split = nums[0];
	int p = 0, q = (int)nums.size() - 1;
	if (nums[0] > nums.back()) {
		while (q != p + 1) {
			int midPoint = nums[(p + q) / 2];
			if (midPoint >= split)
				p = (p + q) / 2;
			else
				q = (p + q) / 2;
		}
	} else {
		p = (int)nums.size() - 1;
	}
	int low = target >= split? 0: q,
		high = target>= split? p: (int)nums.size() - 1;
	while (low != (low + high)/2) {
		int midPoint = nums[(low + high)/2];
		if (midPoint <= target)
			low = (low + high)/2;
		else
			high = (low + high)/2;
	}
	if (nums[low] == target)
		return low;
	else if (nums[high] == target)
		return high;
	else
		return -1;
}