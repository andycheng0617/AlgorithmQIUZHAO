#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int nthUglyNumber1(int n) {
		if (n == 1) return 1;
		int count = 1;
		for (int i = 2; i <= INT_MAX; i++) {
			if (isUglyNumber(i)) {
				count++;
				if (count == n) return i;
			}
		}
		return count;
	}
	bool isUglyNumber(int num) {
		while (num % 2 == 0) {
			num /= 2;
		}
		while (num % 3 == 0) {
			num /= 3;
		}
		while (num % 5 == 0) {
			num /= 5;
		}
		return (num == 1) ? true : false;
	}

	//¶¯Ì¬¹æ»®
	int nthUglyNumber(int n) {
		int a = 0, b = 0, c = 0;
		vector<int> dp(n);
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
			dp[i] = min(min(n2, n3), n5);
			if (dp[i] == n2) a++;
			if (dp[i] == n3) b++;
			if (dp[i] == n5) c++;
		}
		return dp[dp.size() - 1];
	}

};


int main264() {

	Solution solve;
	cout << solve.nthUglyNumber(11);

	return 0;
}