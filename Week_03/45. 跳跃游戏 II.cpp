#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
	//������ҳ���λ��
	//ʱ�临�Ӷȣ�O(n^2))������ n �����鳤�ȡ�
	//�ռ临�Ӷȣ�O(1)
	int jump(vector<int>& nums) {
		int position = nums.size() - 1;
		int steps = 0;
		while (position > 0) {
			for (int i = 0; i < position; i++) {
				if (i + nums[i] >= position) {
					position = i;
					steps++;
					break;
				}
			}
		}
		return steps;
	}

	//������ҿɵ�������λ��
	//ʱ�临�Ӷȣ�O(n)������n�����鳤�ȡ�
	//�ռ临�Ӷȣ�O(1)
	int jump2(vector<int>& nums) {
		int size = nums.size();
		int end = 0;
		int maxPosition = 0;
		int steps = 0;
		for (int i = 0; i < size - 1; i++) {
			maxPosition = max(maxPosition, i + nums[i]);
			if (i == end) {
				end = maxPosition;
				steps++;
			}
		}
		return steps;
	}
};

int main45() {

	vector<int> grid = { 2, 3, 1, 1, 4};

	Solution solve;
	cout << solve.jump(grid);

	return 0;
}