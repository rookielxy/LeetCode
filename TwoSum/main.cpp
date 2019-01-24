#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main() {
	string str;
	getline(cin, str);
	stringstream ss;
	ss << str;
	int data, target;
	vector<int> nums;
	while (ss >> data)
		nums.emplace_back(data);
	cin >> target;
	vector<int> ret = twoSum(nums, target);
	cout << ret[0] << endl
		<< ret[1] << endl;
	return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {
	struct Tuple {
		int val;
		unsigned indice;
	};
	vector<Tuple> tuples(nums.size());
	for (unsigned i = 0; i < nums.size(); ++i) {
		tuples[i].val = nums[i];
		tuples[i].indice = i;
	}
	sort(tuples.begin(), tuples.end(), [](Tuple x, Tuple y)->bool { return x.val < y.val; });
	unsigned p = 0, q = (unsigned)tuples.size() - 1;
	while (p != q) {
		if (tuples[p].val + tuples[q].val == target) {
			vector<int> ret;
			ret.emplace_back(tuples[p].indice);
			ret.emplace_back(tuples[q].indice);
			return ret;
		} else if (tuples[p].val + tuples[q].val < target) {
			++p;
		} else
			--q;
	}
	assert(false);
}