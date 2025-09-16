#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

constexpr int MAX = std::numeric_limits<int>::max() / 2 - 1;

void Print(const vector<vector<int>>& Board)
{
	for (const auto& board : Board)
	{
		for (const auto b : board)
		{
			cout << (b == MAX ? -1 : b) << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Dijkstar(int n, int Start, vector<vector<int>>& Dijk, const vector<vector<int>>& fares)
{
	for (int i = 0; i < n; i++)
	{
		Dijk[i][i] = 0;
	}
	for (const auto& fare : fares)
	{
		Dijk[fare[0] - 1][fare[1] - 1] = fare[2];
		Dijk[fare[1] - 1][fare[0] - 1] = fare[2];
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> BFS;
	BFS.emplace(0, Start, Start);
	while (!BFS.empty())
	{
		auto [Weight, Prev, Now] = BFS.top();
		BFS.pop();

		cout << Prev << ", " << Now << ", " << Weight << endl;

		Dijk[Start][Now] = min(Dijk[Start][Now], Weight);

		for (int i = 0; i < n; i++)
		{
			if (Dijk[Now][i] == MAX || Now == i) continue;
			if (Dijk[Start][i] < Weight + Dijk[Now][i]) continue;

			BFS.emplace(Weight + Dijk[Now][i], Now, i);
		}
	}
	Print(Dijk);
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = MAX;

	// 경로 초기화
	vector<vector<int>> Board(n, vector<int>(n, MAX));

	// fares로 기본 초기화
	for (const auto& fare : fares)
	{
		// u-v 노드 간의 가중치 w
		int u = fare[0] - 1;
		int v = fare[1] - 1;
		int w = fare[2];

		Board[u][v] = w;
		Board[v][u] = w;
	}
	Print(Board);

	// 3번의 다익스트라
	vector<vector<vector<int>>> Dijk(3, vector<vector<int>>(n, vector<int>(n, MAX)));
	Dijkstar(n, s - 1, Dijk[0], fares);
	Dijkstar(n, a - 1, Dijk[1], fares);
	Dijkstar(n, b - 1, Dijk[2], fares);

	for (int i = 0; i < n; i++)
	{
		if (Dijk[0][s - 1][i] == MAX || Dijk[1][a - 1][i] == MAX || Dijk[2][b - 1][i] == MAX) continue;
		answer = min(answer, Dijk[0][s-1][i] + Dijk[1][a - 1][i] + Dijk[2][b - 1][i]);
	}

	return answer;
}

int main()
{
	cout << solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} }) << endl;;
	cout << solution(7, 3, 4, 1, { {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} }) << endl;;
	cout << solution(6, 4, 5, 6, { {2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9} }) << endl;;
}