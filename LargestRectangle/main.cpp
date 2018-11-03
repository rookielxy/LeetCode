#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int> heights);

int main() {
	vector<int> heights;
	int data;
	while (cin >> data)
		heights.emplace_back(data);
	cout << largestRectangleArea(heights) << endl;
	return 0;
}

int largestRectangleArea(vector<int> heights) {
	if (heights.empty())
		return 0;
	if (heights.size() == 1)
		return heights[0];

	heights.emplace_back(0);
	stack<int> bound;
	int ret = 0;
	for (int i = 0; i < heights.size(); ++i) {
		while (not bound.empty() and heights[i] < heights[bound.top()]) {
			int lower = heights[bound.top()];
			bound.pop();
			int length = bound.empty()? i : i - bound.top() - 1;
			ret = max(ret, length*lower);
		}
		bound.push(i);
	}
	return ret;
}