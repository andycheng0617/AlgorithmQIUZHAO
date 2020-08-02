#include<vector>
#include<queue>
#include<iostream>
using namespace std;



class Solution {
public:

	
	double myPow(double x, int n) {
		long long N = n;
		return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
	}

	//方法一：快速幂 + 递归
	//时间复杂度：O(logn)，即为递归的层数。
	//空间复杂度：O(logn)，即为递归的层数。这是由于递归的函数调用会使用栈空间。
	double quickMul1(double x, long long N) {
		if (N == 0) {
			return 1.0;
		}
		double y = quickMul(x, N / 2);
		return N % 2 == 0 ? y * y : y * y * x;
	}


	//方法二：快速幂 + 迭代
	//时间复杂度：O(log n)，即为对 n 进行二进制拆分的时间复杂度。
	//空间复杂度：O(1)
	double quickMul(double x, long long N) {
		double ans = 1.0;
		// 贡献的初始值为 x
		double x_contribute = x;
		// 在对 N 进行二进制拆分的同时计算答案
		while (N > 0) {
			if (N % 2 == 1) {
				// 如果 N 二进制表示的最低位为 1，那么需要计入贡献
				ans *= x_contribute;
			}
			// 将贡献不断地平方
			x_contribute *= x_contribute;
			// 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
			N /= 2;
		}
		return ans;
	}

};


int main() {

	Solution solve;
	cout << solve.myPow(2.00000, 10);

	return 0;
}