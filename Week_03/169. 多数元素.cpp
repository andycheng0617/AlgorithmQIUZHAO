#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:

	//哈希表
	//时间复杂度：O(n)，其中 nn 是数组 nums 的长度。
	//空间复杂度：O(n)
	int majorityElement1(vector<int>& nums) {
		unordered_map<int, int> counts;
		int majority = 0, cnt = 0;
		for (int num : nums) {
			++counts[num];
			if (counts[num] > cnt) {
				majority = num;
				cnt = counts[num];
			}
		}
		return majority;
	}
	//排序
	//时间复杂度：O(nlogn)。将数组排序的时间复杂度为O(nlogn)
	//空间复杂度：O(logn)
	int majorityElement2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}

	//随机化
	// 期望的时间复杂度为 O(n)
	// 空间复杂度：O(1)。随机方法只需要常数级别的额外空间。
	int majorityElement3(vector<int>& nums) {
		while (true) {
			int candinate = nums[rand() % nums.size()];
			int count = 0;
			for (int num : nums) {
				if (num == candinate) {
					count++;
				}
			}
			if (count > nums.size() / 2) {
				return candinate;
			}
		}
		return -1;
	}

	//分治
	//时间复杂度：O(nlogn)。
	//空间复杂度：O(logn)
	int majorityElement4(vector<int>& nums) {
		return majorityElement_recur(nums, 0, nums.size() - 1);
	}

	//Boyer-Moore 投票算法
	//时间复杂度：O(n)。Boyer - Moore 算法只对数组进行了一次遍历。
	//空间复杂度：O(1)。Boyer - Moore 算法只需要常数级别的额外空间。
	int majorityElement(vector<int>& nums) {
		int candinate = -1;
		int count = 0;
		for (int num : nums) {
			if (num == candinate) {
				count++;
			} else if (--count < 0) {
				candinate = num;
				count = 1;
			}
		}
		return candinate;
	}

private:
	int majorityElement_recur(vector<int>& nums, int left, int right) {
		if (left == right) return nums[left];
		int mid = (left + right) / 2;
		int left_majority = majorityElement_recur(nums, left, mid);
		int right_majority = majorityElement_recur(nums, mid + 1, right);
		if (count_in_range(nums, left_majority, left, right) > (right - left + 1) / 2) {
			return left_majority;
		}
		if (count_in_range(nums, right_majority, left, right) > (right - left + 1) / 2) {
			return right_majority;
		}
		return -1;
	}
	int count_in_range(vector<int>& nums, int target, int left, int right) {
		int count = 0;
		for (int i = left; i <= right; i++) {
			if (nums[i] == target) {
				count++;
			}
		}
		return count;
	}

};

int main169() {

	vector<int> nums = { 1, 2, 5, 5, 3, 4 };

	Solution solve;
	int res = solve.majorityElement(nums);
	cout << res;

	return 0;
}

