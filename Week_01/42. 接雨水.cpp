#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	/*ջʵ��
	ʱ�临�Ӷȣ�O(n)�����α���O(n)��ÿ�����ο�����������(����ջ�ĵ���͵���)�����ҵ���͵���ջ����(1)
	�ռ临�Ӷȣ�O(n)��ջ����ڽ����ͻ�ƽ̹�����ο�ṹ��ռ��O(n)�Ŀռ䡣
	*/
	int trap(vector<int>& height) {
		int capacity = 0;
		int current = 0, size = height.size();
		stack<int> stk;
		while (current < size) {
			while (!stk.empty() && height[current] > height[stk.top()]) {
				int top = stk.top();
				stk.pop();
				if (stk.empty()) break;
				int dis = current - stk.top() - 1;
				capacity += (min(height[current], height[stk.top()]) - height[top]) * dis;
			}
			stk.push(current++);
		}
		return capacity;
	}
};