#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;


class Solution {
public:
	int climbStairs1(int n) {
		if (n == 1 || n == 2) return n;
		return  climbStairs1(n - 1) + climbStairs(n - 2);
	}
	//������ظ�������
	int climbStairs2(int n) {
		if (n == 1 || n == 2) return n;
		int f1 = 3, f2 = 0, f = 0;
		for (int i = 1; i <= n; i++) {
			f = f1 + f2;
			f1 = f2;
			f2 = f;
		}
		return  f;
	}

	//���仯�Զ����µķ���
	//ʱ�临�Ӷȣ�O(N)��
	//�ռ临�Ӷȣ�O(N)���ڴ���ʹ�õĶ�ջ��С��
	int climbStairs(int N) {
		if (N == 1 || N == 2) return N;
		vector<int> cache(N);
		cache[0] = 1;
		cache[1] = 2;
		for (int i = 2; i <= N - 1; i++) {
			cache[i] = cache[i - 1] + cache[i - 2];
		}
		return cache[N - 1];
	}

};


int main70p() {
	Solution solve;
	cout << solve.climbStairs(25);
	return 0;
};