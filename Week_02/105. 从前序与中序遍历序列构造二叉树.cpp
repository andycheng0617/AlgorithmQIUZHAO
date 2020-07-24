#include <iostream>
#include <vector>
#include <unordered_map>
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

	//方法1：迭代
	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		// 构造哈希映射，帮助快速定位根节点
		for (int i = 0; i < n; i++) {
			index[inorder[i]] = i;
		}
		return recur_BuildTree(preorder, 0, n - 1, inorder, 0, n - 1);
	}

	TreeNode* recur_BuildTree(vector<int>& preorder, int pre_start_idx, int pre_end_idx, 
								vector<int>& inorder, int in_start_idx, int in_end_idx) {

		if (pre_start_idx > pre_end_idx) return nullptr;

		// 前序遍历中的第一个节点就是根节点(索引下标)
		int pre_root_idx = pre_start_idx;
		// 在中序遍历中定位根节点(索引下标)
		int in_root_idx = index[preorder[pre_root_idx]];

		// 先把根节点建立出来
		TreeNode* root = new TreeNode(preorder[pre_root_idx]);

		// 得到左子树中的节点数目
		int num_node_of_left_tree = in_root_idx - in_start_idx;
		// 递归地构造左子树，并连接到根节点
		// 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
		root->left = recur_BuildTree(preorder, pre_start_idx + 1, pre_start_idx + num_node_of_left_tree, inorder, in_start_idx, in_root_idx - 1);
		// 递归地构造右子树，并连接到根节点
		// 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
		root->right = recur_BuildTree(preorder, pre_start_idx + 1 + num_node_of_left_tree, pre_end_idx, inorder, in_root_idx + 1, in_end_idx);
		return root;
	}

	//方法2：递归
	//时间复杂度：O(n)，其中 nn 是树中的节点个数。
	//空间复杂度：O(n)
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return nullptr;
		
		stack<TreeNode*> stk;

		TreeNode* root = new TreeNode(preorder[0]);
		stk.push(root);

		int inorder_idx = 0;
		for (int i = 1; i < preorder.size(); ++i) {
			int pre_val = preorder[i];
			TreeNode* node = stk.top();
			if (node->val != inorder[inorder_idx]) {
				node->left = new TreeNode(pre_val);
				stk.push(node->left);
			} else {
				while (!stk.empty() && stk.top()->val == inorder[inorder_idx]) {
					node = stk.top();
					stk.pop();
					++inorder_idx;
				}
				node->right = new TreeNode(pre_val);
				stk.push(node->right);
			}
		}
		return root;
	}


private:
	unordered_map<int, int> index;
};


int main() {

	vector<int> preorder = { 3, 9, 20, 15 ,7 };
	vector<int> inorder = { 9, 3 ,15, 20, 7 };

	Solution solve;
	TreeNode* root = solve.buildTree(preorder, inorder);
	

	return 0;
}