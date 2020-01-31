#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);
void dfs(vector<int>& nums, int idx, int target);
void twoSumHelper(vector<int>& nums, int start, int target);
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
vector<int> cand;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	dfs(nums, 0, target);
	return deduplicate(ans);
}

void dfs(vector<int>& nums, int idx, int target) {
	if (idx == nums.size())
		return;
	assert(idx >= 0 and idx < nums.size());
	cand.emplace_back(nums[idx]);
	if (cand.size() == 2)
		twoSumHelper(nums, idx + 1, target - nums[idx]);
	dfs(nums, idx + 1, target - nums[idx]);
	cand.pop_back();
	dfs(nums, idx + 1, target);
}

void twoSumHelper(vector<int>& nums, int start, int target) {
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
			if (nums[q] == nums[q - 1])
				--q;
			else
				++p;
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