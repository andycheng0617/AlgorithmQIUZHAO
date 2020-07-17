#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;


class Solution {
public:
	vector<int> twoSum1(vector<int>& nums, int target) {
		vector<int> res;
		for (int i = 0;i < nums.size() - 1;i++) {
			for (int j = i + 1;j < nums.size();j++) {
				if (nums[i] + nums[j] == target) {
					res.push_back(i);
					res.push_back(j);
				}
			}
		}
		return res;
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		map<int, int> num2index;
		for (int i = 0;i < nums.size();i++) {
			if (num2index.find(target - nums[i]) != num2index.end()) {
				res.push_back(i);
				res.push_back(num2index[target - nums[i]]);
				return res;
			}
			num2index[nums[i]] = i;
		}
	}

};


int main12sum() {

	vector<int> strs = { 2, 7, 11, 15 };

	Solution solve;
	vector<int> res = solve.twoSum(strs, 9);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}

	return 0;
}