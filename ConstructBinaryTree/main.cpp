#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void parseInput(vector<int>& pre, vector<int>& post);
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post);
void printTree(TreeNode* root);

int main() {
	vector<int> pre, post;
	parseInput(pre, post);
	TreeNode *root = constructFromPrePost(pre, post);
	printTree(root);
	return 0;
}


/**
 * There may exist multiple answer given pre-order and post-order traversal,
 * we prefer to put nodes in left subtree if possible
 */
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
	assert(pre.size() == post.size());
	if (pre.empty())
		return nullptr;


	auto *root = new TreeNode(pre.front());
	if (pre.size() == 1)
		return root;

	int leftRootVal = pre[1], leftRootIdx = 0;
	for (int i = 0; i < post.size(); ++i) {
		if (post[i] == leftRootVal) {
			leftRootIdx = i;
			break;
		}
	}

	int leftLength = leftRootIdx + 1;
	vector<int> leftPre(pre.begin() + 1, pre.begin() + 1 + leftLength),
				rightPre(pre.begin() + 1 + leftLength, pre.end());
	vector<int> leftPost(post.begin(), post.begin() + leftLength),
				rightPost(post.begin() + leftLength, --post.end());
	root->left = constructFromPrePost(leftPre, leftPost);
	root->right = constructFromPrePost(rightPre, rightPost);
	return root;
}

void parseInput(vector<int>& pre, vector<int>& post) {
	stringstream ss;
	string str;
	int ele;
	getline(cin, str);
	ss << str;
	while (ss >> ele)
		pre.emplace_back(ele);

	ss.clear();
	getline(cin, str);
	ss << str;
	while (ss >> ele)
		post.emplace_back(ele);
}

void printTree(TreeNode* root) {
	if (root == nullptr) {
		cout << "null ";
		return;
	}
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}