#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		string temp = "";
		vector<vector<string>> res;
		map<string, vector<string>> word_index;
		for (int i = 0;i < strs.size();i++) {
			temp = strs[i];
			sort(temp.begin(), temp.end());
			if (word_index.find(temp) != word_index.end()) {
				vector<string> indexs;
				indexs.push_back(strs[i]);
				word_index[temp] = indexs;
			} else {
				word_index[temp].push_back(strs[i]);
			}
		}
		map<string, vector<string>>::iterator it;
		for (it = word_index.begin(); it != word_index.end(); it++) {
			res.push_back(it->second);
		}
		return res;
	}

};


int main49() {

	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };

	Solution solve;
	vector<vector<string>> res = solve.groupAnagrams(strs);
	for (int i = 0; i < res.size(); i++) {
		
	}

	return 0;
}