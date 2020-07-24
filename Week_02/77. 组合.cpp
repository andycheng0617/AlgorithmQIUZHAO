#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

	//»ØËİËã·¨ + ¼ôÖ¦
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		// ÌØÅĞ
		if (n <= 0 || k <= 0 || n < k) return res;
		
		vector<int> path;
		dfs(n, k, 1, path, &res);
		return res;

	}
	void dfs(int n, int k, int start, vector<int> &path, vector<vector<int>>* res) {
		if (path.size() == k) {
			res->push_back(path);
			return;
		}

		for (int i = start; i <= n - (k - path.size()) + 1; ++i) {
			path.push_back(i);
			dfs(n, k, i + 1, path, res);
			path.pop_back();

		}
	}
};


int main77() {

	Solution solve;
	vector<vector<int>> res = solve.combine(4, 2);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}

	return 0;
}