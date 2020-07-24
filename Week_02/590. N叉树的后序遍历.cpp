#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;


class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


class Solution {
public:

	//µÝ¹é
	vector<int> postorder1(Node* root) {
		vector<int> res;
		helper(root, &res);
		return res;
	}
	void helper(Node* root, vector<int>* res) {
		if (root == NULL) return;
		for (int i = 0; i < root->children.size(); i++) {
			helper(root->children[i], res);
		}
		res->push_back(root->val);
	}

	//µü´ú
	vector<int> postorder(Node* root) {
		vector<int> res;
		if (root == NULL) return res;
		stack<Node*> stk;
		stk.push(root);
		while (!stk.empty()) {
			Node* temp = stk.top();
			stk.pop();
			int size = temp->children.size();
			for (int i = 0; i <= size - 1; i++) {
				stk.push(temp->children[i]);
			}
			res.push_back(temp->val);
		}
		reverse(res.begin(), res.end());
		return res;
	}


};


int main590() {

	Node node5(5);
	Node node6(6);

	Node node3(3, { &node5 ,&node6 });

	Node node2(2);
	Node node4(4);

	Node node1(1, { &node3 ,&node2 ,&node4 });

	Solution solve;
	vector<int> res = solve.postorder(&node1);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}

	return 0;
}