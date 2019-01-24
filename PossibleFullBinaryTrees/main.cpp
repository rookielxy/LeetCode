#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> allPossibleFBT(int N);
void displayTreeNode(TreeNode* root);

int main() {
	int N;
	cin >> N;
	vector<TreeNode*> ret = allPossibleFBT(N);
	for (TreeNode *root : ret) {
		displayTreeNode(root);
		cout << endl;
	}
	return 0;
}

vector<TreeNode*> allPossibleFBT(int N) {
	assert(N%2 == 1);
	int n = N/2;
	vector<vector<TreeNode*>> table((unsigned)n + 1);
	table[0].emplace_back(new TreeNode(0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i + 1; ++j) {
			int k = i + 1 - j;
			for (int count1 = 0; count1 < table[j - 1].size(); ++count1) {
				for (int count2 = 0; count2 < table[k - 1].size(); ++count2) {
					auto node = new TreeNode(0);
					node->left = table[j - 1][count1];
					node->right = table[k - 1][count2];
					table[i].emplace_back(node);
				}
			}
		}
	}
	return table.back();
}

void displayTreeNode(TreeNode* root) {
	assert(root != nullptr);
	cout << root->val << ", ";
	if (root->left == nullptr)
		cout << "null";
	else
		displayTreeNode(root->left);
	cout << ", ";
	if (root->right == nullptr)
		cout << "null";
	else
		displayTreeNode(root->right);
}