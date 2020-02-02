#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);
void twoSumHelper(const vector<int>& nums, const vector<int>& cand, int start, int target);
vector<vector<int>> deduplicate(vector<vector<int>>& ret);

int main() {
	int ele, target;
	vector<int> arr;
	stringstream ss;
	string temp;

	getline(cin, temp);
	ss << temp;
	while (ss >> ele)
		arr.emplace_back(ele);
	cin >> target;

	vector<vector<int>> ret = fourSum(arr, target);
	ret = deduplicate(ret);
	for (const vector<int>& elem : ret) {
		for (int num : elem)
			cout << num << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<int>> ans;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i = 0; i < n - 3; ++i) {
		if (target < 0 and nums[i] >= 0)
			break;
		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
			break;
		if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
			continue;
		if (i > 0 and nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < n - 2; ++j) {
			if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
				break;
			if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
				continue;
			if (j > i + 1 and nums[j] == nums[j - 1])
				continue;
			vector<int> cand = {nums[i], nums[j]};
			twoSumHelper(nums, cand, j + 1, target - nums[i] - nums[j]);
		}
	}
	return ans;
}

void twoSumHelper(const vector<int>& nums, const vector<int>& cand, int start, int target) {
	int p = start, q = (int)nums.size() - 1;
	while (p < q) {
		if (nums[p] + nums[q] < target)
			++p;
		else if (nums[p] + nums[q] > target)
			--q;
		else {
			vector<int> temp(cand);
			temp.emplace_back(nums[p]);
			temp.emplace_back(nums[q]);
			ans.emplace_back(temp);
			int oldP = p, oldQ = q;
			while (p < q and nums[p] == nums[oldP])
				++p;
			while (p < q and nums[q] == nums[oldQ])
				--q;
		}
	}
}

vector<vector<int>> deduplicate(vector<vector<int>>& ret) {
	vector<vector<int>> temp;

	sort(ret.begin(), ret.end(),
			[](const vector<int>& v1, const vector<int>& v2) -> bool {
		if (v1.size() != v2.size())
			return v1.size() < v2.size();
		for (int i = 0; i < v1.size(); ++i) {
			if (v1[i] == v2[i])
				continue;
			return v1[i] < v2[i];
		}
		return false;
	});

	for (const vector<int>& ele : ret) {
		if (temp.empty() or temp.back() != ele)
			temp.emplace_back(ele);
	}
	return temp;
}