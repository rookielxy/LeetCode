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
TreeNode* recursiveHelper(vector<int>& pre, vector<int>& post, int, int, int, int);
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
	return recursiveHelper(pre, post, 0, pre.size(), 0, post.size());
}

TreeNode* recursiveHelper(vector<int>& pre, vector<int>& post, int preS, int preE, 
							int postS, int postE) {
	assert(preE - preS == postE - postS and preE >= preS);
	if (preE == preS)
		return nullptr;
	auto *root = new TreeNode(pre[preS]);
	if (preE - preS == 1)
		return root;

	int leftRootVal = pre[preS + 1], leftRootIdx = -1;
	for (int i = postS; i < postE; ++i) {
		if (post[i] == leftRootVal) {
			leftRootIdx = i;
			break;
		}
	}
	int leftLen = leftRootIdx - postS + 1;
	root->left = recursiveHelper(pre, post, preS + 1, preS + 1 + leftLen,
			postS, postS + leftLen);
	root->right = recursiveHelper(pre, post, preS + 1 + leftLen, preE,
			postS + leftLen, postE - 1);
	return root;
}

void parseInput(vector<int>& pre, vector<int>& post) {
	stringstream ss;
	string str;
	int ele = 0;
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