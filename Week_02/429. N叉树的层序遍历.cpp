#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
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
	//递归
	vector<vector<int>> levelOrder1(Node* root) {
		vector<vector<int>> res;
		if (root != NULL) traverseNode(root, 0, &res);
		return res;
	}
	void traverseNode(Node* root, int level, vector<vector<int>>* res) {
		if (res->size() <= level) {
			vector<int> t;
			res->push_back(t);
		}
		res->at(level).push_back(root->val);
		for (int i = 0; i < root->children.size(); i++) {
			traverseNode(root->children[i], level + 1, res);
		}
	}

	//迭代：队列
	//时间复杂度：O(n)。n 指的是节点的数量。
	//空间复杂度：O(n)，列表包含所有节点。
	vector<vector<int>> levelOrder2(Node* root) {
		vector<vector<int>> res;
		if (root == NULL) return res;
		queue<pair<Node*, int>> que;
		que.push(pair<Node*, int>(root, 0));
		while (!que.empty()) {
			pair<Node*, int> node = que.front();
			if (res.size() <= node.second) {
				res.push_back(vector<int>());
			}
			res.at(node.second).push_back(node.first->val);
			que.pop();

			for (int i = 0; i < node.first->children.size(); i++) {
				que.push(pair<Node*, int>(node.first->children[i], node.second + 1));
			}
		}
		return res;
	}

	//迭代：队列
	//时间复杂度：O(n)。n 指的是节点的数量。
	//空间复杂度：O(n)，列表包含所有节点。
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> res;
		if (root == NULL) return res;
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			vector<int> temp;
			int size = que.size();
			for (int i = 0; i < size; i++) {
				Node* node = que.front();
				que.pop();
				temp.push_back(node->val);
				for (int i = 0; i < node->children.size(); i++) {
					que.push(node->children[i]);
				}
			}
			res.push_back(temp);
		}
		return res;
	}


};


int main429() {

	Node node5(5);
	Node node6(6);

	Node node3(3, { &node5 ,&node6 });

	Node node2(2);
	Node node4(4);

	Node node1(1, { &node3 ,&node2 ,&node4 });

	Solution solve;
	vector<vector<int>> res = solve.levelOrder(&node1);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}

	return 0;
}