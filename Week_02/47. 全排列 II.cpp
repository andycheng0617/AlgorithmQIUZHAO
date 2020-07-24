#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

	//回溯算法
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> res;
		if (len == 0) return res;

		// 排序（升序或者降序都可以），排序是剪枝的前提
		sort(nums.begin(), nums.end());

		vector<bool> used(len);
		vector<int> path;
		dfs(nums, len, 0, path, &used, &res);
		return res;
	}
	void dfs(vector<int> nums, int len, int depth, vector<int> path, vector<bool>* used, vector<vector<int>>* res) {
		if (depth == len) {
			res->push_back(path);
			return;
		}
		for (int i = 0; i < len; i++) {
			if (used->at(i)) continue;

			// 剪枝条件：i > 0 是为了保证 nums[i - 1] 有意义
			// 写 !used[i - 1] 是因为 nums[i - 1] 在深度优先遍历的过程中刚刚被撤销选择
			if (i > 0 && nums[i] == nums[i - 1] && !used->at(i - 1)) continue;

			path.push_back(nums[i]);
			used->at(i) = true;
			dfs(nums, len, depth + 1, path, used, res);//状态重置，是从深层结点回到浅层结点的过程，代码在形式上和递归之前是对称的
			used->at(i) = false;
			path.pop_back();
		}
	}
};


int main47() {

	vector<int> nums = { 1, 1, 2 };
	Solution solve;
	vector<vector<int>> res = solve.permuteUnique(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}

	return 0;
}