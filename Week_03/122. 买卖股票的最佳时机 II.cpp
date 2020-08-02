#include<vector>
#include<queue>
#include<iostream>
using namespace std;



class Solution {
public:
	//̰���㷨
	//ʱ�临�Ӷȣ�O(N)������ N ��ʾ�ɼ�����ĳ��ȣ�
	//�ռ临�Ӷȣ�O(1)
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