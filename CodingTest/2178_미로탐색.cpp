#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

const vector<pair<int, int>> Move = {
	{+1,0},
	{0,+1},
	{-1,0},
	{0,-1},
};

int main()
{
	int Answer = 0;
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> Board;
	for (int i = 0; i < N; i++)
	{
		string Temp;
		cin >> Temp;

		vector<bool> Line;
		Line.reserve(M);
		for (const auto& s : Temp)
		{
			if (s == '1')
				Line.push_back(true);
			else
				Line.push_back(false);
		}
		Board.push_back(Line);
	}

	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> BFS;
	vector<vector<bool>> Visited(N, vector<bool>(M, 0));
	BFS.emplace(1, 0, 0, 0);
	while (!BFS.empty())
	{
		auto [Weight, Huristic, X, Y] = BFS.top();
		BFS.pop();

		Weight -= Huristic;
		//cout << X << ", " << Y << ", " << Weight << endl;

		if (X == M - 1 && Y == N - 1)
		{
			Answer = Weight;
			break;
		}

		Visited[Y][X] = true;
		for (const auto& move : Move)
		{
			int NewX = move.first + X;
			int NewY = move.second + Y;

			if (NewX < 0 || NewX >= M || NewY < 0 || NewY >= N ||
				Visited[NewY][NewX] || !Board[NewY][NewX]) continue;

			int Huristic = (M - 1) - NewX + (N - 1) - NewY;

			BFS.emplace(Weight + 1 + Huristic, Huristic, NewX, NewY);
		}
	}

	cout << Answer << endl;
}