#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;



class Solution {
public:

	bool isAnagram1(string s, string t) {
		string tmp1 = s;
		sort(tmp1.begin(), tmp1.end());
		string tmp2 = s;
		sort(tmp2.begin(), tmp2.end());
		if (tmp1 == tmp2) return true;
		return false;
	}

	bool isAnagram2(string s, string t) {
		map<char, int> char2num;
		for (int i = 0;i < s.length();i++) {
			if (char2num.find(s[i]) == char2num.end()) {
				char2num[s[i]] = 1;
			} else {
				char2num[s[i]] = char2num[s[i]] + 1;
			}
		}
		for (int i = 0;i < t.length();i++) {
			if (char2num.find(t[i]) == char2num.end()) {
				return false;
			} else {
				char2num[t[i]] = char2num[t[i]] - 1;
			}
		}
		map<char, int>::iterator it;
		for (it = char2num.begin(); it != char2num.end(); it++) {
			if (it->second != 0) return false;
		}
		return true;
	}

	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;

		int counter[26] = {0};
		for (int i = 0; i < s.length(); i++) {
			counter[s[i] - 'a']++;
			counter[t[i] - 'a']--;
		}
		for (int i = 0;i < 26;i++) {
			if (counter[i] != 0) return false;
		}
		return true;
	}


};

int main() {
	string s = "anagram", t = "nagaram";
	Solution solve;
	cout << solve.isAnagram(s, t);
	return 0;
}