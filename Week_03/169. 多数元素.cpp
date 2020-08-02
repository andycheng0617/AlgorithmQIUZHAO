#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:

	//��ϣ��
	//ʱ�临�Ӷȣ�O(n)������ nn ������ nums �ĳ��ȡ�
	//�ռ临�Ӷȣ�O(n)
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
	//����
	//ʱ�临�Ӷȣ�O(nlogn)�������������ʱ�临�Ӷ�ΪO(nlogn)
	//�ռ临�Ӷȣ�O(logn)
	int majorityElement2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}

	//�����
	// ������ʱ�临�Ӷ�Ϊ O(n)
	// �ռ临�Ӷȣ�O(1)���������ֻ��Ҫ��������Ķ���ռ䡣
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

	//����
	//ʱ�临�Ӷȣ�O(nlogn)��
	//�ռ临�Ӷȣ�O(logn)
	int majorityElement4(vector<int>& nums) {
		return majorityElement_recur(nums, 0, nums.size() - 1);
	}

	//Boyer-Moore ͶƱ�㷨
	//ʱ�临�Ӷȣ�O(n)��Boyer - Moore �㷨ֻ�����������һ�α�����
	//�ռ临�Ӷȣ�O(1)��Boyer - Moore �㷨ֻ��Ҫ��������Ķ���ռ䡣
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

