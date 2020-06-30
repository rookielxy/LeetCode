#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(const vector<int>& nums);
bool isCompleteTree(TreeNode* root);

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto root = buildTree(input);
    if (isCompleteTree(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

TreeNode* buildTree(const vector<int>& nums) {
    if (nums.empty())
        return nullptr;

    auto root = new TreeNode(nums[0]);

    queue<TreeNode*> q;
    bool left = true;

    q.push(root);
    for (int i = 1; i < (int)nums.size(); ++i) {
        auto ptr = q.front();
        if (nums[i] != -1) {
            if (left) {
                ptr->left = new TreeNode(nums[i]);
                q.push(ptr->left);
            } else {
                ptr->right = new TreeNode(nums[i]);
                q.push(ptr->right);
            }
        }
        if (not left)
            q.pop();
        left = !left;
    }

    return root;
}

bool isCompleteTree(TreeNode* root) {
    if (root == nullptr)
        return false;

    bool encounterNull = false;
    queue<TreeNode*> q;

    q.push(root);
    while (not q.empty()) {
        auto ptr = q.front();
        if (ptr->left) {
            if (encounterNull)
                return false;
            q.push(ptr->left);
            if (ptr->right)
                q.push(ptr->right);
            else
                encounterNull = true;
        } else if (not ptr->left and ptr->right) {
            return false;
        } else {
            encounterNull = true;
            // do nothing
        }
        q.pop();
    }

    return true;
}
