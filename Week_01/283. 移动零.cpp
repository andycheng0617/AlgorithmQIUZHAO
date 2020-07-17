#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int j = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				j++;
			}
		}
	}

	void moveZeroes1(vector<int>& nums) {
		int j = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				nums[j] = nums[i];
				if (i != j) {
					nums[i] = 0;
				}
				j++;
			}

		}
	}
};