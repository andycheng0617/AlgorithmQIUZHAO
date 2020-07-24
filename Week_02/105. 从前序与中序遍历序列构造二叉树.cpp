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

	//����1������
	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		// �����ϣӳ�䣬�������ٶ�λ���ڵ�
		for (int i = 0; i < n; i++) {
			index[inorder[i]] = i;
		}
		return recur_BuildTree(preorder, 0, n - 1, inorder, 0, n - 1);
	}

	TreeNode* recur_BuildTree(vector<int>& preorder, int pre_start_idx, int pre_end_idx, 
								vector<int>& inorder, int in_start_idx, int in_end_idx) {

		if (pre_start_idx > pre_end_idx) return nullptr;

		// ǰ������еĵ�һ���ڵ���Ǹ��ڵ�(�����±�)
		int pre_root_idx = pre_start_idx;
		// ����������ж�λ���ڵ�(�����±�)
		int in_root_idx = index[preorder[pre_root_idx]];

		// �ȰѸ��ڵ㽨������
		TreeNode* root = new TreeNode(preorder[pre_root_idx]);

		// �õ��������еĽڵ���Ŀ
		int num_node_of_left_tree = in_root_idx - in_start_idx;
		// �ݹ�ع����������������ӵ����ڵ�
		// ��������С��� ��߽�+1 ��ʼ�� size_left_subtree����Ԫ�ؾͶ�Ӧ����������С��� ��߽� ��ʼ�� ���ڵ㶨λ-1����Ԫ��
		root->left = recur_BuildTree(preorder, pre_start_idx + 1, pre_start_idx + num_node_of_left_tree, inorder, in_start_idx, in_root_idx - 1);
		// �ݹ�ع����������������ӵ����ڵ�
		// ��������С��� ��߽�+1+�������ڵ���Ŀ ��ʼ�� �ұ߽硹��Ԫ�ؾͶ�Ӧ����������С��� ���ڵ㶨λ+1 �� �ұ߽硹��Ԫ��
		root->right = recur_BuildTree(preorder, pre_start_idx + 1 + num_node_of_left_tree, pre_end_idx, inorder, in_root_idx + 1, in_end_idx);
		return root;
	}

	//����2���ݹ�
	//ʱ�临�Ӷȣ�O(n)������ nn �����еĽڵ������
	//�ռ临�Ӷȣ�O(n)
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