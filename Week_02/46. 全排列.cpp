#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

	//回溯算法
	vector<vector<int>> permute(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> res;
		if (len == 0) return res;

		vector<bool> used(len);
		vector<int> path;
		dfs(nums, len, 0, path, used, &res);
		return res;
	}
	void dfs(vector<int> nums, int len, int depth, vector<int> path, vector<bool> used, vector<vector<int>>* res) {
		if (depth == len) {
			res->push_back(path);
			return;
		}
		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				path.push_back(nums[i]);
				used[i] = true;
				dfs(nums, len, depth + 1, path, used, res);//状态重置，是从深层结点回到浅层结点的过程，代码在形式上和递归之前是对称的
				used[i] = false;
				path.pop_back();
			}
		}
	}
};


int main46() {

	vector<int> nums = { 1, 2, 3 };
	Solution solve;
	vector<vector<int>> res = solve.permute(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}

	return 0;
}