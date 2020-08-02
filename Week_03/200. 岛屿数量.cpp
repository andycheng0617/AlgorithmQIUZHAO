#include<vector>
#include<queue>
#include<iostream>
using namespace std;



class Solution {
public:
	//DFS
	int numIslands1(vector<vector<char>>& grid) {
		int rows = grid.size();
		if (rows == 0) return 0;
		int cols = grid[0].size();
		vector<vector<bool>> marked(rows, vector<bool>(cols));
		int count = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				// ����ǵ����е�һ���㣬����û�б����ʹ�
				// �ͽ���������ȱ���
				if (!marked[i][j] && grid[i][j] == '1') {
					count++;
					dfs(i, j, rows, cols, grid, marked);
				}
			}
		}
		return count;
	}

	//BFS
	int numIslands(vector<vector<char>>& grid) {
		static const vector<vector<int>> directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

		int rows = grid.size();
		if (rows == 0) return 0;
		int cols = grid[0].size();
		vector<vector<bool>> marked(rows, vector<bool>(cols));
		int count = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				// ����ǵ����е�һ���㣬����û�б����ʹ�
				// ������Ϊ (i,j) �ĵ㿪ʼ���й�����ȱ���
				if (!marked[i][j] && grid[i][j] == '1') {
					count++;
					queue<int> _queue;
					// С���ɣ�������ת��Ϊһ������
					// ���򣬵���һ������棬�� Python �У�����ʹ�� tuple ��
					_queue.push(i * cols + j);
					// ע�⣺����Ҫ������Ѿ����ʹ�
					marked[i][j] = true;
					while (!_queue.empty()) {
						int cur = _queue.front();
						_queue.pop();
						int curX = cur / cols;
						int curY = cur % cols;
						// �õ� 4 �����������
						for (int k = 0; k < 4; k++) {
							int newX = curX + directions[k][0];
							int newY = curY + directions[k][1];
							// �����Խ�硢û�б����ʹ������һ�Ҫ��½�أ��Ҿͼ���������У�������е�ͬʱ��Ҫ�ǵñ���Ѿ����ʹ�
							if (inArea(newX, newY, rows, cols) && grid[newX][newY] == '1' && !marked[newX][newY]) {
								_queue.push(newX * cols + newY);
								// ���ر�ע�⡿�ڷ�������Ժ�Ҫ���ϱ�ǳ��Ѿ����ʹ�������Ҳ��ʮ������ģ�����ֻҪ�����˶��У�����綼���������
								// �������ڳ����е�ʱ���ٱ��
								// ���ر�ע�⡿����ǳ����е�ʱ���ٱ�ǣ�����ɺܶ��ظ��Ľ�������У�����ظ��Ĳ�������仰�����û��д�Եط�����������س�ʱ��
								marked[newX][newY] = true;
							}
						}
					}
				}
			}

		}
		return count;
	}



private:

	// ������Ϊ (i,j) �ĵ㿪ʼ����������ȱ���
	void dfs(int i, int j, int rows, int cols, vector<vector<char>>& grid, vector<vector<bool>>& marked) {

		static const vector<vector<int>> directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

		marked[i][j] = true;
		// �õ� 4 �����������
		for (int k = 0; k < 4; k++) {
			int newX = i + directions[k][0];
			int newY = j + directions[k][1];
			// �����Խ�硢û�б����ʹ������һ�Ҫ��½��
			if (inArea(newX, newY, rows, cols) && grid[newX][newY] == '1' && !(marked[newX][newY])) {
				dfs(newX, newY, rows, cols, grid, marked);
			}
		}
	}

	// ��װ�� inArea �������������
	bool inArea(int x, int y, int rows, int cols) {
		// ���ںŲ�Ҫ����
		return x >= 0 && x < rows && y >= 0 && y < cols;
	}

};


int main200() {

	vector<vector<char>> grid = { {'1','1','1','1','0'},
									{'1','1','0','1','0'},
									{'1','1','0','0','0'},
									{'0','0','0','0','0'}
								};

	Solution solve;
	cout << solve.numIslands(grid);

	return 0;
}