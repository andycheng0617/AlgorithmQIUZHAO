#include<vector>
#include<queue>
#include<iostream>
using namespace std;



class Solution {
public:
	//贪心算法
	//时间复杂度：O(N)，这里 N 表示股价数组的长度；
	//空间复杂度：O(1)
	int maxProfit(vector<int>& prices) {
		int res = 0;
		for (int i = 0;i < prices.size() - 1;i++) {
			if (prices[i + 1] > prices[i]) {
				res += prices[i + 1] - prices[i];
			}
		}
		return res;
	}
};

int main122() {

	vector<int> nums = { 7,1,5,3,6,4 };

	Solution solve;
	cout << solve.maxProfit(nums);

	return 0;
}