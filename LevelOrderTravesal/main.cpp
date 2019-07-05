#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& input);
vector<vector<int>> levelOrder(TreeNode* root);

int main() {
	string str;
	stringstream ss;
	vector<string> input;

	getline(cin, str);
	ss << str;
	while (ss >> str)
		input.emplace_back(str);

	auto root = buildTree(input);
	auto ret = levelOrder(root);
	for (const auto& line : ret) {
		for (auto ele : line)
			cout << ele << " ";
		cout << endl;
	}
	return 0;
}

TreeNode* buildTree(const vector<string>& input) {
	if (input.empty())
		return nullptr;
	if (input.size() == 1 and input[0] == "null")
		return nullptr;
	int val;
	sscanf(input[0].c_str(), "%d", &val);
	auto root = new TreeNode(val);

	int p = 1, count = 0;
	while (p < input.size()) {
		if (count == 1)
			break;
		if (input[p] == "null")
			++count;
		else
			--count;
		++p;
	}
	root->left = buildTree(vector<string>(input.begin() + 1, input.begin() + p));
	root->right = buildTree(vector<string>(input.begin() + p, input.end()));
	return root;
}

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ret;

	if (root == nullptr)
		return ret;

	queue<TreeNode*> parent, child;
	parent.push(root);

	while (not parent.empty()) {
		vector<int> parentVals;
		while (not parent.empty()) {
			parentVals.emplace_back(parent.front()->val);
			if (parent.front()->left != nullptr)
				child.push(parent.front()->left);
			if (parent.front()->right != nullptr)
				child.push(parent.front()->right);
			parent.pop();
		}
		ret.emplace_back(parentVals);
		parent = child;
		while (not child.empty())
			child.pop();
	}
	return ret;
}