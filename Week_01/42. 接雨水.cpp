#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	/*栈实现
	时间复杂度：O(n)。单次遍历O(n)，每个条形块最多访问两次(由于栈的弹入和弹出)，并且弹入和弹出栈都是(1)
	空间复杂度：O(n)。栈最多在阶梯型或平坦型条形块结构中占用O(n)的空间。
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