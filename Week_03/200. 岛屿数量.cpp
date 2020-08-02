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
				// 如果是岛屿中的一个点，并且没有被访问过
				// 就进行深度优先遍历
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
				// 如果是岛屿中的一个点，并且没有被访问过
				// 从坐标为 (i,j) 的点开始进行广度优先遍历
				if (!marked[i][j] && grid[i][j] == '1') {
					count++;
					queue<int> _queue;
					// 小技巧：把坐标转换为一个数字
					// 否则，得用一个数组存，在 Python 中，可以使用 tuple 存
					_queue.push(i * cols + j);
					// 注意：这里要标记上已经访问过
					marked[i][j] = true;
					while (!_queue.empty()) {
						int cur = _queue.front();
						_queue.pop();
						int curX = cur / cols;
						int curY = cur % cols;
						// 得到 4 个方向的坐标
						for (int k = 0; k < 4; k++) {
							int newX = curX + directions[k][0];
							int newY = curY + directions[k][1];
							// 如果不越界、没有被访问过、并且还要是陆地，我就继续放入队列，放入队列的同时，要记得标记已经访问过
							if (inArea(newX, newY, rows, cols) && grid[newX][newY] == '1' && !marked[newX][newY]) {
								_queue.push(newX * cols + newY);
								// 【特别注意】在放入队列以后，要马上标记成已经访问过，语义也是十分清楚的：反正只要进入了队列，你迟早都会遍历到它
								// 而不是在出队列的时候再标记
								// 【特别注意】如果是出队列的时候再标记，会造成很多重复的结点进入队列，造成重复的操作，这句话如果你没有写对地方，代码会严重超时的
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

	// 从坐标为 (i,j) 的点开始进行深度优先遍历
	void dfs(int i, int j, int rows, int cols, vector<vector<char>>& grid, vector<vector<bool>>& marked) {

		static const vector<vector<int>> directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

		marked[i][j] = true;
		// 得到 4 个方向的坐标
		for (int k = 0; k < 4; k++) {
			int newX = i + directions[k][0];
			int newY = j + directions[k][1];
			// 如果不越界、没有被访问过、并且还要是陆地
			if (inArea(newX, newY, rows, cols) && grid[newX][newY] == '1' && !(marked[newX][newY])) {
				dfs(newX, newY, rows, cols, grid, marked);
			}
		}
	}

	// 封装成 inArea 方法语义更清晰
	bool inArea(int x, int y, int rows, int cols) {
		// 等于号不要忘了
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