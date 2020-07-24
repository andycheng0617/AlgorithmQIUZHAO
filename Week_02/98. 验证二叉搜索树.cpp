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
	long inorder = LONG_MIN;
	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;
		if (!isValidBST(root->left)) return false;
		if (root->val < inorder) return false;
		inorder = root->val;
		return isValidBST(root->right);
	}

	
};


int main98() {

	TreeNode node5(5);
	TreeNode node1(1);
	TreeNode node4(4);
	TreeNode node3(3);
	TreeNode node6(6);

	node5.left = &node1;
	node5.right = &node4;

	node4.left = &node3;
	node4.right = &node6;

	Solution solve;
	cout << solve.isValidBST(&node1);

	return 0;
}