#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		// '.' 表示空，'Q' 表示皇后，初始化空棋盘。
		vector<string> board(n, string(n, '.'));
		backtrack(board, 0, &res);
		return res;
	}

	// 路径：board 中小于 row 的那些行都已经成功放置了皇后
	// 选择列表：第 row 行的所有列都是放置皇后的选择
	// 结束条件：row 超过 board 的最后一行
	void backtrack(vector<string>& board, int row, vector<vector<string>>* res) {
		// 触发结束条件
		if (row == board.size()) {
			res->push_back(board);
			return;
		}

		int n = board[row].size();
		for (int col = 0; col < n; col++) {
			// 排除不合法选择
			if (!isValid(board, row, col))
				continue;
			// 做选择
			board[row][col] = 'Q';
			// 进入下一行决策
			backtrack(board, row + 1, res);
			// 撤销选择
			board[row][col] = '.';
		}
	}

	/* 是否可以在 board[row][col] 放置皇后？ */
	bool isValid(vector<string>& board, int row, int col) {
		int n = board.size();
		// 检查列是否有皇后互相冲突
		for (int i = 0; i < n; i++) {
			if (board[i][col] == 'Q')
				return false;
		}
		// 检查右上方是否有皇后互相冲突
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
			if (board[i][j] == 'Q')
				return false;
		}
		// 检查左上方是否有皇后互相冲突
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j] == 'Q')
				return false;
		}
		return true;
	}

};

int main51() {

	std::vector<std::vector<std::string>> result;

	Solution solve;
	result = solve.solveNQueens(4);

	for (int i = 0; i < result.size(); i++) {

		cout << "i = " << i << endl;

		for (int j = 0; j < result[i].size(); j++) {

			cout << result[i][j].c_str() << endl;

		}
		cout << endl;;
	}

	return 0;
};