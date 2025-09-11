#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
	int x;
	int y;
	int value;
	Node():x(0),y(0),value(0) {}
	Node(int X, int Y, int Value):x(X), y(Y), value(Value) {}
};

int main()
{
	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> Board(N, vector<int>(M, 0));
	vector<vector<int>> Ans(N, vector<int>(M, -1));
	vector<vector<bool>> Visited(N, vector<bool>(M, false));

	int StartX, StartY;
	const vector<pair<int, int>> Direction = {
		pair<int,int>(1, 0),
		pair<int,int>(0, 1),
		pair<int,int>(-1, 0),
		pair<int,int>(0, -1)
	};

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Board[i][j];
			if (Board[i][j] == 2)
			{
				StartX = j;
				StartY = i;
			}
		}
	}

	queue<Node> BFS;
	BFS.push(Node(StartX, StartY, 0));
	while (!BFS.empty())
	{
		Node NowPos = BFS.front();
		BFS.pop();

		if (NowPos.x < 0 ||	NowPos.x >= M ||
			NowPos.y < 0 || NowPos.y >= N ||
			Board[NowPos.y][NowPos.x] == 0 ||
			Visited[NowPos.y][NowPos.x])
			continue;

		Ans[NowPos.y][NowPos.x] = NowPos.value;// min(Ans[NowPos.y][NowPos.x], NowPos.value);
		Visited[NowPos.y][NowPos.x] = true;

		for (const auto& d : Direction)
		{
			BFS.push(Node(NowPos.x + d.first, NowPos.y + d.second, NowPos.value + 1));
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Ans[i][j] == -1)
			{
				if (Board[i][j] == 0)
					cout << 0 << " ";
				else
					cout << -1 << " ";

			}
			else
				cout << Ans[i][j] << " ";
		}
		cout << endl;
	}
}