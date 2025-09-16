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

void FloydWarshall(int s, const vector<vector<int>>& fares, vector<vector<int>>& board)
{
	for (int i = 0; i < s; i++)
	{
		board[i][i] = 0;
	}
	for (auto& fare : fares)
	{
		board[fare[0] - 1][fare[1] - 1] = fare[2];
		board[fare[1] - 1][fare[0] - 1] = fare[2];
	}

	for (int k = 0; k < s; k++)
	{
		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < s; j++)
			{
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = MAX;

	// ��� �ʱ�ȭ
	vector<vector<int>> Board(n, vector<int>(n, MAX));

	// fares�� �⺻ �ʱ�ȭ
	for (const auto& fare : fares)
	{
		// u-v ��� ���� ����ġ w
		int u = fare[0] - 1;
		int v = fare[1] - 1;
		int w = fare[2];

		Board[u][v] = w;
		Board[v][u] = w;
	}
	Print(Board);

	// i, j ����� �ִ� �Ÿ� ���ϱ�
	vector<vector<int>> Warshall(n, vector<int>(n, MAX));
	FloydWarshall(n, fares, Warshall);
	Print(Warshall);

	// 4������ ����ؼ� �����ϴ� ��� �߿� ���ΰ����� �ּڰ� ã��
	for (int i = 0; i < n; i++)
	{
		if (Warshall[s - 1][i] == MAX || Warshall[i][a - 1] == MAX || Warshall[i][b - 1] == MAX)
			continue;
		answer = min(answer, Warshall[s - 1][i] + Warshall[i][a - 1] + Warshall[i][b - 1]);
	}

	// // ���� �������� ��� ����� ����� �˾Ƴ��� (���� �ý�)
	// priority_queue<tuple<int, int, int>> Dijk;
	// vector<bool> Visited(s, false);
	// vector<int> DistFromStart(s, MAX);
	// Dijk.emplace(s - 1, s - 1, 0);
	// while (!Dijk.empty())
	// {
	// 	auto [PrevNode, NowNode, Weight] = Dijk.top();
	// 	Dijk.pop();
	// 
	// 	Visited[NowNode] = true;
	// 	DistFromStart[NowNode] = min(DistFromStart[NowNode], Weight);
	// 
	// 	for (int i = 0; i < s; i++)
	// 	{
	// 		if (NowNode == i || Board[NowNode][i] == MAX || Visited[i]) continue;
	// 		Dijk.emplace(NowNode, i, Weight + Board[NowNode][i]);
	// 	}
	// }
	// for (const auto& aaa : DistFromStart)
	// 	cout << aaa << ", ";
	// cout << endl;
	// Print(Board);

	// ���� �������� ������ ���� ������ ���� ����� ����Ѵ�



	return answer;
}

int main()
{
	cout << solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} }) << endl;;
	cout << solution(7, 3, 4, 1, { {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} }) << endl;;
	cout << solution(6, 4, 5, 6, { {2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9} }) << endl;;
}