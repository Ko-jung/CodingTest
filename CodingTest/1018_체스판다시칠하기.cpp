#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<char>> Board(N, vector<char>(M, ' '));
	for (auto& board : Board)
		for (auto& b : board)
			cin >> b;

	// 4Pointer?
	int StartX = 0, EndX = 0, StartY = 0, EndY = 0;
	vector<tuple<int, int, int>> WindowX(8, tuple<int, int, int>());
	vector<tuple<int, int, int>> WindowY(8, tuple<int, int, int>());

	// EndX 이동
	for (int i = 0; i < 8; i++)
	{
		auto& [Start, End, UnStableCount] = WindowX[i];
		for (End = 1; End < 8; End++)
		{
			if (Board[i][End] == Board[i][End - 1])
				UnStableCount++;
		}
		//cout << UnStableCount << ", ";
	}
	//cout << endl;
	// EndY 이동
	for (int i = 0; i < 8; i++)
	{
		auto& [Start, End, UnStableCount] = WindowY[i];
		for (End = 1; End < 8; End++)
		{
			if (Board[End][i] == Board[End - 1][i])
				UnStableCount++;
		}
	}

	// StartX 이동
	for (int i = 0; i < 8; i++)
	{
		auto& [Start, End, UnStableCount] = WindowX[i];
		for (Start; Start < M - 8; Start++)
		{
			if (Board[i][End] == Board[i][End - 1])
				UnStableCount++;
		}
		//cout << UnStableCount << ", ";
	}
}