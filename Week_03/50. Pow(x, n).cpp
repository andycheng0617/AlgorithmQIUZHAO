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

	//����һ�������� + �ݹ�
	//ʱ�临�Ӷȣ�O(logn)����Ϊ�ݹ�Ĳ�����
	//�ռ临�Ӷȣ�O(logn)����Ϊ�ݹ�Ĳ������������ڵݹ�ĺ������û�ʹ��ջ�ռ䡣
	double quickMul1(double x, long long N) {
		if (N == 0) {
			return 1.0;
		}
		double y = quickMul(x, N / 2);
		return N % 2 == 0 ? y * y : y * y * x;
	}


	//�������������� + ����
	//ʱ�临�Ӷȣ�O(log n)����Ϊ�� n ���ж����Ʋ�ֵ�ʱ�临�Ӷȡ�
	//�ռ临�Ӷȣ�O(1)
	double quickMul(double x, long long N) {
		double ans = 1.0;
		// ���׵ĳ�ʼֵΪ x
		double x_contribute = x;
		// �ڶ� N ���ж����Ʋ�ֵ�ͬʱ�����
		while (N > 0) {
			if (N % 2 == 1) {
				// ��� N �����Ʊ�ʾ�����λΪ 1����ô��Ҫ���빱��
				ans *= x_contribute;
			}
			// �����ײ��ϵ�ƽ��
			x_contribute *= x_contribute;
			// ���� N �����Ʊ�ʾ�����λ����������ÿ��ֻҪ�ж����λ����
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