#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//µÝ¹é
	vector<int> inorderTraversal1(TreeNode* root) {
		vector<int> res;
		helper(root, &res);
		return res;
	}

	void helper(TreeNode* root, vector<int>* res) {
		if (root == NULL) return;
		helper(root->left, res);
		res->push_back(root->val);
		helper(root->right, res);
	}

	//µü´ú
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == NULL) return res;

		stack<TreeNode*> stack;

		TreeNode* current = root;
		while (current != NULL || !stack.empty()) {
			while (current != NULL) {
				stack.push(current);
				current = current->left;
			}
			current = stack.top();
			stack.pop();
			res.push_back(current->val);
			current = current->right;
		}
		return res;
	}

};


int main94() {

	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);

	node1.right = &node2;
	node2.left = &node3;


	Solution solve;
	vector<int> res = solve.inorderTraversal(&node1);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}

	return 0;
}