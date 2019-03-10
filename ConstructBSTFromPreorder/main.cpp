#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	  int val;
	  TreeNode *left;
	  TreeNode *right;
	  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };


TreeNode* bstFromPreorder(vector<int>& preorder);
TreeNode* bstFromPreorder(vector<int>::iterator begin, vector<int>::iterator end);

int main() {
	stringstream ss;
	string str;
	int data;
	vector<int> preorder;
	getline(cin, str);
	ss << str;
	while (ss >> data)
		preorder.emplace_back(data);
	TreeNode* root = bstFromPreorder(preorder);
	return 0;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
	return bstFromPreorder(preorder.begin(), preorder.end());
}

TreeNode* bstFromPreorder(vector<int>::iterator begin, vector<int>::iterator end) {
	if (begin == end)
		return nullptr;
	auto root = new TreeNode(*begin);
	auto it = ++begin;
	while (it < end and *it < root->val) {
		++it;
	}
	root->left = bstFromPreorder(begin, it);
	root->right = bstFromPreorder(it, end);
	return root;
}