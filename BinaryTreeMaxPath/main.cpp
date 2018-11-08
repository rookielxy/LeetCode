#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int> &list, int nullVal);
TreeNode* buildTree(vector<int>::iterator p, vector<int>::iterator q, int nullVal);
int maxPathSum(TreeNode* root);
int maxRootPath(TreeNode* root);

int main() {
	int nullVal, data;
	vector<int> input;
	cin >> nullVal;
	while (cin >> data)
		input.emplace_back(data);
	TreeNode *root = buildTree(input, nullVal);
	cout << maxPathSum(root) << endl;
}

int maxPathSum(TreeNode* root) {
	assert(root != nullptr);
	int left = max(0, maxRootPath(root->left)),
		right = max(0, maxRootPath(root->right));
	int sum = root->val + left + right;
	if (root->left == nullptr and root->right == nullptr)
		return sum;
	else if (root->left == nullptr)
		return max(sum, maxPathSum(root->right));
	else if (root->right == nullptr)
		return max(sum, maxPathSum(root->left));
	else
		return max(sum, max(maxPathSum(root->left), maxPathSum(root->right)));
}

int maxRootPath(TreeNode* root) {
	if (root == nullptr)
		return 0;
	int leftPath = (root->left == nullptr)? 0 : maxRootPath(root->left),
		rightPath = (root->right == nullptr)? 0 : maxRootPath(root->right);
	return root->val + max(0, max(leftPath, rightPath));
}

TreeNode* buildTree(vector<int> &list, int nullVal) {
	return buildTree(list.begin(), list.end(), nullVal);
}

TreeNode* buildTree(vector<int>::iterator p, const vector<int>::iterator q, int nullVal) {
	if (*p == nullVal)
		return nullptr;
	auto root = new TreeNode(*p);
	int count = 0;
	auto it = ++p;
	while (it != q and count != 1) {
		if (*it == nullVal)
			++count;
		else
			--count;
		++it;
	}
	root->left = buildTree(p, it, nullVal);
	root->right = buildTree(it, q, nullVal);
	return root;
}