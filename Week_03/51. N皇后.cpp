#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		// '.' ��ʾ�գ�'Q' ��ʾ�ʺ󣬳�ʼ�������̡�
		vector<string> board(n, string(n, '.'));
		backtrack(board, 0, &res);
		return res;
	}

	// ·����board ��С�� row ����Щ�ж��Ѿ��ɹ������˻ʺ�
	// ѡ���б��� row �е������ж��Ƿ��ûʺ��ѡ��
	// ����������row ���� board �����һ��
	void backtrack(vector<string>& board, int row, vector<vector<string>>* res) {
		// ������������
		if (row == board.size()) {
			res->push_back(board);
			return;
		}

		int n = board[row].size();
		for (int col = 0; col < n; col++) {
			// �ų����Ϸ�ѡ��
			if (!isValid(board, row, col))
				continue;
			// ��ѡ��
			board[row][col] = 'Q';
			// ������һ�о���
			backtrack(board, row + 1, res);
			// ����ѡ��
			board[row][col] = '.';
		}
	}

	/* �Ƿ������ board[row][col] ���ûʺ� */
	bool isValid(vector<string>& board, int row, int col) {
		int n = board.size();
		// ������Ƿ��лʺ����ͻ
		for (int i = 0; i < n; i++) {
			if (board[i][col] == 'Q')
				return false;
		}
		// ������Ϸ��Ƿ��лʺ����ͻ
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
			if (board[i][j] == 'Q')
				return false;
		}
		// ������Ϸ��Ƿ��лʺ����ͻ
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