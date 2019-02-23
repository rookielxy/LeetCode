#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool PredictTheWinner(vector<int>& nums);

int main() {
	stringstream ss;
	string str;
	int data;
	vector<int> nums;

	getline(cin, str);
	ss << str;
	while (ss >> data)
		nums.emplace_back(data);
	if (PredictTheWinner(nums))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}

bool PredictTheWinner(vector<int>& nums) {
	if (nums.size()%2 == 0 or nums.size() == 1)
		return true;
	vector<vector<int>> matrix(nums.size());
	for (vector<int>& array : matrix)
		array.resize(nums.size());

	for (int i = 0; i < nums.size(); ++i)
		matrix[i][i] = nums[i];
	for (int j = 0; j < nums.size(); ++j) {
		for (int i = j - 1; i >= 0; --i) {
			int factor1 = (i + 2 < matrix.size() and i + 2 <= j)? matrix[i + 2][j] : 0;
			int factor2 = (i + 1 < matrix.size() and j - 1 >= 0 and i + 1 <= j - 1)? matrix[i + 1][j - 1] : 0;
			int factor3 = (j - 2 >= 0 and i <= j - 2)? matrix[i][j - 2] : 0;
			int solution1 = nums[i] + min(factor1, factor2);
			int solution2 = nums[j] + min(factor2, factor3);
			matrix[i][j] = max(solution1, solution2);
		}
	}
	int sum = 0;
	for (int ele : nums)
		sum += ele;
	return 2*matrix[0][nums.size() - 1] >= sum;
}