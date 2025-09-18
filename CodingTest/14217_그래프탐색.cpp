#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

constexpr int MAX = numeric_limits<int>::max();

void Print(const vector<vector<int>>& Board)
{

	for (auto board : Board)
	{
		for (auto b : board)
			cout << (b == MAX ? -1 : b) << ", ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> Roads;
	for (int i = 0; i < M; i++)
	{
		int First, Second;
		cin >> First >> Second;
		Roads.emplace_back(First, Second);
	}

	int Q;
	cin >> Q;
	vector<tuple<int, int, int>> Plans;
	for (int i = 0; i < Q; i++)
	{
		int a, k, j;
		cin >> a >> k >> j;
		Plans.emplace_back(a, k, j);
	}

	vector<vector<int>> Board(N + 1, vector<int>(N + 1, MAX));;
	for (int i = 0; i < Board.size(); i++)
	{
		Board[i][i] = 0;
	}
	for (const auto& road : Roads)
	{
		Board[road.first][road.second] = 1;
		Board[road.second][road.first] = 1;
	}

	// Plan으로 도로가 수정되는 것을 반영
	vector<vector<int>> FixBoard(Board.begin(), Board.end());
	for (const auto& plan : Plans)
	{
		auto [a, i, j] = plan;
		if (a == 1)
		{
			FixBoard[i][j] = 1;
			FixBoard[j][i] = 1;
		}
		else
		{
			FixBoard[i][j] = MAX;
			FixBoard[j][i] = MAX;
		}

		// 수도로부터 얼마나 거리가 반영
		vector<vector<int>> Dijkstar(FixBoard.begin(), FixBoard.end());

		//Dijkstar
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> BFS;
		BFS.emplace(0, 1, 1);
		vector<bool> Visited(N + 1, false);
		while (!BFS.empty())
		{
			auto [Weight, Prev, Now] = BFS.top();
			BFS.pop();

			//cout << Weight << ", " << Prev << ", " << Now << endl;

			Dijkstar[1][Now] = min(Dijkstar[1][Now], Weight);
			Visited[Now] = true;

			for (int i = 1; i <= N; i++)
			{
				if (Now == i ||Dijkstar[Now][i] == MAX || Visited[i]) continue;
				if (Weight + Dijkstar[Now][i] > Dijkstar[1][i]) continue;
				BFS.emplace(Weight + Dijkstar[Now][i], Now, i);
			}
		}

		cout	<< (Dijkstar[1][1] == MAX ? -1 : Dijkstar[1][1]) << " "
				<< (Dijkstar[1][2] == MAX ? -1 : Dijkstar[1][2]) << " "
				<< (Dijkstar[1][3] == MAX ? -1 : Dijkstar[1][3]) << " "
				<< (Dijkstar[1][4] == MAX ? -1 : Dijkstar[1][4]) << " "
				<< (Dijkstar[1][5] == MAX ? -1 : Dijkstar[1][5]) << endl;
		//cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	}
}