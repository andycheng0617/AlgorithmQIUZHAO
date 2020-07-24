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
	vector<int> preorderTraversal1(TreeNode* root) {
		vector<int> res;
		_helper(root, &res);
		return res;
	}

	void _helper(TreeNode* root, vector<int>* res) {
		if (root == NULL) return;
		res->push_back(root->val);
		_helper(root->left, res);
		_helper(root->right, res);
	}

	//µü´ú
	vector<int> preorderTraversal2(TreeNode* root) {
		vector<int> res;
		if (root == NULL) return res;
		TreeNode* tmp;
		stack<TreeNode*> stack;
		stack.push(root);
		while (!stack.empty()) {
			tmp = stack.top();
			res.push_back(tmp->val);
			stack.pop();
			if (tmp->right != NULL) stack.push(tmp->right);
			if (tmp->left != NULL) stack.push(tmp->left);
		}
		return res;
	}
};


int main144() {

	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);

	node1.right = &node2;
	node2.left = &node3;


	Solution solve;
	vector<int> res = solve.preorderTraversal2(&node1);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}

	return 0;
}