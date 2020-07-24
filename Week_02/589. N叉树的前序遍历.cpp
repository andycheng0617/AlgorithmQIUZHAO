#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

// Definition for a Node.
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
	vector<int> preorder1(Node* root) {
		vector<int> res;
		_helper(root, &res);
		return res;
	}
	void _helper(Node* root, vector<int>* res) {
		if (root == NULL)  return;
		res->push_back(root->val);
		for (int i = 0;i < root->children.size();i++) {
			_helper(root->children[i], res);
		}
	}
	//µü´ú
	vector<int> preorder2(Node* root) {
		if (root == NULL) return {};
		vector<int> res;
		Node* _top;
		stack<Node*> stack;
		stack.push(root);
		while (!stack.empty()) {
			_top = stack.top();
			res.push_back(_top->val);
			stack.pop();
			for (int i = _top->children.size() - 1; i >= 0; i--) {
				stack.push(_top->children[i]);
			}
			
		}
		return res;
	}
};

int main589() {
	
	Node node5(5);
	Node node6(6);

	Node node3(3, { &node5 ,&node6 });

	Node node2(2);
	Node node4(4);

	Node node1(1, { &node3 ,&node2 ,&node4 });

	Solution solve;
	vector<int> res = solve.preorder2(&node1);
	for (int i = 0; i < res.size(); i++){
		cout << res[i];
	}

	return 0;
}