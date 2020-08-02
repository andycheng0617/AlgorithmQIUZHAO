#include<vector>
#include<queue>
#include<iostream>
using namespace std;


class Solution {
public:

	//¶þ·ÖËÑË÷
	int search1(vector<int>& nums, int target) {
		int n = (int)nums.size();
		if (!n) return -1;
		if (n == 1) return nums[0] == target ? 0 : -1;
		int l = 0, r = n - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] == target) return mid;
			if (nums[0] <= nums[mid]) {
				if (nums[0] <= target && target < nums[mid]) {
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			} else {
				if (nums[mid] < target && target <= nums[n - 1]) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
		}
		return -1;
	}

	int search(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
				lo = mid + 1;
			else
				hi = mid;
		}
		return lo == hi && nums[lo] == target ? lo : -1;
	}
};

int main33() {

	vector<int> nums = { 4,5,6,7,0,1,2 };

	Solution solve;
	cout << solve.search(nums, 0);

	return 0;
}