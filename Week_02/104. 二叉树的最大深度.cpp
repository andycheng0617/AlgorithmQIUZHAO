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
	/*
	递归
	时间复杂度：每个节点仅遍历一次，O(n)，n为二叉树的节点个数
	空间复杂度：O(n)，n为二叉树的节点个数
	*/
	int maxDepth1(TreeNode* root) {
		if (root == NULL) return 0;
		int l_height = maxDepth1(root->left);
		int r_height = maxDepth1(root->right);
		return max(l_height, r_height) + 1;
	}

	/*
	迭代
	时间复杂度：
	空间复杂度：
	*/
	int maxDepth2(TreeNode* root) {

		stack<pair<TreeNode*, int>> stack;
		if (root != NULL) {
			stack.push(pair<TreeNode*, int>(root, 1));
		}

		int depth = 0, current_depth = 0;
		pair<TreeNode*, int> currnet;
		while (!stack.empty()) {
			currnet = stack.top();
			stack.pop();
			root = currnet.first;
			current_depth = currnet.second;
			if (root != NULL) {
				depth = max(depth, current_depth);
				stack.push(pair<TreeNode*, int>(root->left, current_depth + 1));
				stack.push(pair<TreeNode*, int>(root->right, current_depth + 1));
			}
		}
		return depth;


	}
};



int main104() {

	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);

	node1.right = &node2;
	node2.left = &node3;


	Solution solve;
	int res = solve.maxDepth2(&node1);
	cout << res;

	return 0;
}