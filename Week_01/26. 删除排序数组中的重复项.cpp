#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (!nums.size()) return 0;
		int j = 0;
		for (int i = 1;i < nums.size();i++) {
			if (nums[j] != nums[i]) {
				nums[++j] = nums[i];
			}
		}
		return j + 1;
	};
};

int main26() {
	vector<int> nums = { 0, 0, 5, 5, 1, 1, 1, 2, 2, 3, 3, 4 };
	Solution solve;
	int len = solve.removeDuplicates(nums);
	cout << len << endl;
	for (int i = 0; i < len; i++) {
		cout << (nums[i]);
	}

	return 0;
}