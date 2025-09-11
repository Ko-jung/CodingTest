#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
int K;

int DFS(vector<vector<char>>& Board, int x, int y, int count)
{
	static const vector<pair<int, int>> Direct = {
		pair<int, int>(0, 1),
		pair<int, int>(1, 0),
		pair<int, int>(0, -1),
		pair<int, int>(-1, 0),
		pair<int, int>(1, -1),
		pair<int, int>(-1, 1),
		pair<int, int>(1, 1),
		pair<int, int>(-1, -1),
	};

	if (x < 0 || x >= N || y < 0 || y >= M ||
		Board[y][x] == '#')
		return count - 1;

	Board[y][x] = '#';

	for (const auto& d : Direct)
	{
		count = DFS(Board, x + d.first, y + d.second, count + 1);
	}
	return count;
}

int main()
{
	cin >> M >> N;

	vector<vector<char>> Board(M, vector<char>(N, '#'));
	for (auto& board : Board)
		for (auto& b : board)
			cin >> b;
	cin >> K;

	int THCount = 0;
	int MaxTHSize = 0;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Board[i][j] == '.') {
				int Size = DFS(Board, j, i, 1);
				MaxTHSize = max(MaxTHSize, Size);
				if (Size > K)
					THCount++;
			}
		}
	}

	cout << THCount << " " << MaxTHSize;
}