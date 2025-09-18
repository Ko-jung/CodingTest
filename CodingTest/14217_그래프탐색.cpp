#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>

using namespace std;

constexpr int MAX = numeric_limits<int>::max();

void Print(const vector<vector<bool>>& Board)
{
	cout << "======================" << endl;
	for (auto board : Board)
	{
		for (auto b : board)
			cout << (b ? 1 : 0) << ", ";
		cout << endl;
	}
	cout << "======================" << endl;
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

	vector<vector<bool>> Board(N + 1, vector<bool>(N + 1, false));;
	for (int i = 0; i < Board.size(); i++)
	{
		Board[i][i] = true;
	}
	for (const auto& road : Roads)
	{
		Board[road.first][road.second] = true;
		Board[road.second][road.first] = true;
	}

	for (const auto& plan : Plans)
	{
		auto [a, i, j] = plan;
		if (a == 1)
		{
			Board[i][j] = true;
			Board[j][i] = true;
		}
		else
		{
			Board[i][j] = false;
			Board[j][i] = false;
		}
		//Print(Board);

		//Board
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> BFS;
		BFS.emplace(0, 1, 1);
		vector<bool> Visited(N + 1, false);
		vector<int> Ans(N + 1, 0);
		Ans[1] = 0;
		Visited[1] = true;
		while (!BFS.empty())
		{
			auto [Weight, Prev, Now] = BFS.top();
			BFS.pop();

			//cout << Weight << ", " << Prev << ", " << Now << endl;
			Ans[Now] = Weight;

			for (int i = 1; i <= N; i++)
			{
				if (Now == i || !Board[Now][i] || Visited[i]) continue;
				Visited[i] = true;
				BFS.emplace(Weight + 1, Now, i);
			}

		}
		for (int i = 1; i <= N; i++)
		{
			if(Visited[i])
				cout << Ans[i] << " ";
			else
				cout << -1 << " ";
		}
		cout << endl;
		//cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	}
}