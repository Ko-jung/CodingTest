#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>

using namespace std;

constexpr int MAX = numeric_limits<int>::max();

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> Board(N, vector<int>(N, MAX));

	vector<tuple<int, int, int>> Bus(M, tuple<int, int, int>());
	for (auto& bus : Bus)
	{
		auto& [i, j, w] = bus;
		cin >> i >> j >> w;
		--i, --j;

		Board[i][j] = min(Board[i][j], w);
	}

	int Start, End;
	cin >> Start >> End;
	--Start, --End;

	// Dijkstar
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> BFS;
	vector<bool> Visited(N, false);
	BFS.emplace(0, Start, Start);
	while (!BFS.empty())
	{
		auto [Weight, Prev, Now] = BFS.top();
		BFS.pop();

		Board[Start][Now] = min(Board[Start][Now], Weight);
		Visited[Now] = true;

		cout << Prev + 1 << ", " << Now + 1 << ", " << Weight << endl;

		for (int i = 0; i < N; i++)
		{
			if (i == Now || Board[Now][i] == MAX || Visited[i]) continue;
			BFS.emplace(Weight + Board[Now][i], Now, i);
		}

		for (auto board : Board)
		{
			for (auto b : board)
				cout << (b == MAX ? -1 : b) << ", ";
			cout << endl;
		}
	}

	cout << Board[Start][End];
}