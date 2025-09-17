// 다시 해보도록
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>

using namespace std;

constexpr int MAX = std::numeric_limits<int>::max() / 2;

void Print(const vector<vector<int>>& Board)
{
	for (const auto& board : Board)
	{
		for (const auto& b : board)
			cout << (b == MAX ? -1 : b) << ", ";
		cout << endl;
	}
	cout << endl;
}

void FloydWashall(int n, int s, vector<vector<int>>& Board)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Board[i][j] = min(Board[i][j], Board[i][k] + Board[k][j]);
			}
		}
	}
}

void Dijkstar(int n, int s, vector<vector<int>>& Board)
{
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> BFS;
	vector<bool> Visited(n, false);
	BFS.emplace(0, s, s);
	while (!BFS.empty())
	{
		auto [Weight, Prev, Now] = BFS.top();
		BFS.pop();

		//cout << Prev << ", " <<  Now << ", " << Weight << endl;

		Board[s][Now] = min(Board[s][Now], Weight);
		Visited[Now] = true;

		for (int i = 0; i < n; i++)
		{
			if (Board[Now][i] == MAX || Visited[i] || i == Now) continue;
			if (Weight + Board[Now][i] > Board[s][i]) continue;
			BFS.emplace(Weight + Board[Now][i], Now, i);
		}
	}

	//Print(Board);
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = MAX;

	vector<vector<vector<int>>> DijkBoard;
	vector<vector<int>> Board(n, vector<int>(n,MAX));
	for (int i = 0; i < n; i++)
	{
		Board[i][i] = 0;
	}
	for (const auto& fare : fares)
	{
		// 주어진 입력은 1~n, 쓰기위해 0~n-1로 조정
		Board[fare[0] - 1][fare[1] - 1] = fare[2];
		Board[fare[1] - 1][fare[0] - 1] = fare[2];
	}

	// for (int i = 0; i < 3; i++)
	// {
	// 	// Dijk 3회 진행할 예정. S->i, i->A, i->B의 최솟값을 찾을 예정
	// 	DijkBoard.emplace_back(Board.begin(), Board.end());
	// }
	// 
	// Dijkstar(n, s - 1, DijkBoard[0]);
	// Dijkstar(n, a - 1, DijkBoard[1]);
	// Dijkstar(n, b - 1, DijkBoard[2]);
	// 
	// for (int i = 0; i < n; i++)
	// {
	// 	if (DijkBoard[0][s - 1][i] == MAX || DijkBoard[1][a - 1][i] == MAX || DijkBoard[2][b - 1][i] == MAX) continue;
	// 	answer = min(answer, DijkBoard[0][s - 1][i] + DijkBoard[1][a - 1][i] + DijkBoard[2][b - 1][i]);
	// }

	FloydWashall(n, s, Board);
	for (int i = 0; i < n; i++)
	{
		if (Board[s - 1][i] == MAX || Board[a - 1][i] == MAX || Board[b - 1][i] == MAX) continue;
		answer = min(answer, Board[s - 1][i] + Board[a - 1][i] + Board[b - 1][i]);
	}

	return answer;
}

int main()
{
	cout << solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} }) << endl;
	cout << solution(7, 3, 4, 1, { {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} }) << endl;
	cout << solution(6, 4, 5, 6, { {2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9} }) << endl;
}