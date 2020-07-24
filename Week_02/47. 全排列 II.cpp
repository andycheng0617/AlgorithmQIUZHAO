#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

	//�����㷨
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> res;
		if (len == 0) return res;

		// ����������߽��򶼿��ԣ��������Ǽ�֦��ǰ��
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

			// ��֦������i > 0 ��Ϊ�˱�֤ nums[i - 1] ������
			// д !used[i - 1] ����Ϊ nums[i - 1] ��������ȱ����Ĺ����иոձ�����ѡ��
			if (i > 0 && nums[i] == nums[i - 1] && !used->at(i - 1)) continue;

			path.push_back(nums[i]);
			used->at(i) = true;
			dfs(nums, len, depth + 1, path, used, res);//״̬���ã��Ǵ������ص�ǳ����Ĺ��̣���������ʽ�Ϻ͵ݹ�֮ǰ�ǶԳƵ�
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