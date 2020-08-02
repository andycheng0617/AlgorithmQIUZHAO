#include<vector>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits == "") {
			return {};
		}

		map<char, vector<char>> dict;
		dict['2'] = { 'a', 'b', 'c' };
		dict['3'] = { 'd', 'e', 'f' };
		dict['4'] = { 'g', 'h', 'i' };
		dict['5'] = { 'j', 'k', 'l' };
		dict['6'] = { 'm', 'n', 'o' };
		dict['7'] = { 'p', 'q', 'r', 's' };
		dict['8'] = { 't', 'u', 'v' };
		dict['9'] = { 'w', 'x', 'y', 'z' };
	    
		vector<string> output = {};
		backtrack("", digits, dict, &output);
		return output;
	}
private:
	void backtrack(string combination, string next_digits, map<char, vector<char>> dict, vector<string>* output) {
		if (next_digits.length() == 0) {
			output->push_back(combination);
		} else {
			vector<char> letters = dict[next_digits[0]];
			for (int i = 0; i < letters.size(); i++) {
				char letter = letters[i];
				backtrack(combination + letter, next_digits.substr(1), dict, output);
			}
		}
	}
};

int main117() {

	string digits = "234";
	Solution solve;
	vector<string> res = solve.letterCombinations(digits);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].c_str() << endl;
	}

	return 0;
}