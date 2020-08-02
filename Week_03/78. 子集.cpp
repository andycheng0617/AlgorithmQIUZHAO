#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:

	//µ›πÈ(ªÿÀ›À„∑®)
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> temp;
		backtrack(0, nums, &res, temp);
		return res;
	}

private:

	void backtrack(int i, vector<int> nums, vector<vector<int>>* res, vector<int> temp) {
		res->push_back(temp);
		for (int j = i; j < nums.size(); j++) {
			temp.push_back(nums[j]);
			backtrack(j + 1, nums, res, temp);
			temp.pop_back();
		}
	}
};


int main78() {

	vector<int> nums = { 1, 2, 3 };

	Solution solve;
	vector<vector<int>> res = solve.subsets(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}

	return 0;
}
