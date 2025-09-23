#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<pair<int, int>> Move = {
	{+1,0},
	{-1,0},
	{0,+1},
	{0,-1},
};
int N, M;

void DFS(vector<vector<int>>& Board, int X, int Y)
{
	Board[Y][X] = 2;
	for (const auto& move : Move)
	{
		int NewX = X + move.first;
		int NewY = Y + move.second;

		if (NewX < 0 || NewX >= M || NewY < 0 || NewY >= N ||
			Board[NewY][NewX] != 0)
			continue;

		DFS(Board, NewX, NewY);
	}
}

int main()
{
	cin >> N >> M;

	vector<vector<int>> Board(N, vector<int>(M, 0));
	vector<int> Combi; Combi.reserve(N * M);
	vector<pair<int, int>> Virus;
	int WallCount = 0;
	for (int i = 0; i < N; i++)
	{
		auto& board = Board[i];
		for (int j = 0; j < M; j++)
		{
			auto& b = board[j];
			cin >> b;
			if (b == 2)
			{
				Virus.emplace_back(i, j);
			}
			if (b == 0)
			{
				Combi.push_back(i * N + j);
			}
			if (b == 1)
				WallCount++;
		}
	}

	vector<bool> BCombi(Combi.size(), false);
	BCombi[0] = BCombi[1] = BCombi[2] = true;
	WallCount += 3;
	int Answer = 0;
	do
	{
		vector<vector<int>> TestBoard(Board.begin(), Board.end());
		vector<vector<bool>> Visited(N, vector<bool>(M, false));
		for (int i = 0; i < BCombi.size(); i++)
		{
			if (BCombi[i])
			{
				TestBoard[Combi[i] / N][Combi[i] % N] = 1;
			}
		}
		int SetVirusCount = 0;
		for (const auto& v : Virus)
		{
			DFS(TestBoard, v.first, v.second);
		}

		int Result = 0;
		for (int i = 0; i < N; i++)
		{
			auto& board = TestBoard[i];
			for (int j = 0; j < M; j++)
			{
				auto& b = board[j];
				if (b == 0)
					Result++;
				//cout << b << ", ";
			}
			//cout << endl;
		}
		Answer = max(Answer, Result);
	} while (prev_permutation(BCombi.begin(), BCombi.end()));

	cout << Answer;
}