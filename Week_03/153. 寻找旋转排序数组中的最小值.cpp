#include<vector>
#include<queue>
#include<iostream>
using namespace std;


class Solution {
public:

	//���ֲ��ҷ��������ʱ�临�Ӷ�ΪO(logN)���ռ临�Ӷ�ΪO(1)
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > nums[right]) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return nums[left];
	}
};

int main153() {

	vector<int> nums = { 3,4,5,1,2 };

	Solution solve;
	cout << solve.findMin(nums);

	return 0;
}