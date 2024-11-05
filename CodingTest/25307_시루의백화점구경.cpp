//시루는 부모님과 함께 백화점에 갔다.
// 부모님은 쇼핑할 것이 많기 때문에 여러 곳을 돌아다녀야 하고,
// 시루는 부모님과 함께 걸어다니는 것이 너무 힘들어서 의자에 앉아서 쉬려고 한다.
//
//백화점은 세로 길이가 N, 가로 길이가 M인 격자 형태이고, 상하좌우로 인접한 칸으로 이동할 때마다 1 만큼의 체력을 소모한다.
// 시루는 현재 위치에서 출발해 백화점 곳곳에 있는 의자 중 하나를 찾아가서 앉으려고 한다.
// 시루는 백화점 밖으로 나가면 부모님께 혼나기 때문에 백화점 밖으로 나갈 수 없다.
//
//백화점에는 건물을 지탱하기 위한 기둥과 옷을 전시하기 위한 마네킹이 있다.
// 시루는 기둥이 있는 칸으로 이동하지 못하고, 마네킹을 무서워하기 때문에 마네킹과 거리가 K 이하인 칸은 사용하지 않으려고 한다.
// 이때 두 칸 (r_x, c_x), (r_y, c_y)의 거리는 |(r_x - r_y) + (c_x - c_y)| 이다.
// 단, 시루가 출발할 때는 부모님과 함께 있기 때문에, 출발 지점과 마네킹과의 거리가 K 이하가 되어도 출발할 수 있다.
//
//시루는 다리가 너무 아프기 때문에 체력 소모를 최소화하면서 의자까지 찾아가려고 한다.시루가 소모하는 체력의 최솟값을 구해보자.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Position
{
	int X;
	int Y;
	int Cost;
};

bool IsNear(int x, int y, int TargetX, int TargetY, int dist)
{
	return (abs(x - TargetX) + abs(y - TargetY)) <= dist;
}

int main()
{
	vector<pair<int, int>> Direction = {
		{1,0},{0,1},{-1,0},{0,-1}
	};

	int M, N, K;
	cin >> N >> M >> K;

	//vector<pair<int, int>> Mannequin;
	queue<Position> MannequinBFS;
	vector<vector<int>> Board(N, vector<int>(M, 0));
	vector<vector<bool>> Banned(N, vector<bool>(M, false));
	vector<vector<bool>> Visited(N, vector<bool>(M, false));
	pair<int, int> StartPos;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Board[i][j];

			if (Board[i][j] == 4)
				StartPos = { j,i };
			if (Board[i][j] == 3)
			{
				MannequinBFS.push({ j,i,K });
				//Mannequin.emplace_back(pair<int, int>{ j,i });
			}
		}
	}

	// 마네킹의 위치를 바탕으로 못가는 위치 정하기
	while (!MannequinBFS.empty())
	{
		Position Pos = MannequinBFS.front();
		MannequinBFS.pop();

		Banned[Pos.Y][Pos.X] = true;
		if (Pos.Cost <= 0) continue;

		for (const auto& d : Direction)
		{
			int NewX = Pos.X + d.first;
			int NewY = Pos.Y + d.second;

			if (NewX < 0 || NewY < 0 || NewX >= M || NewY >= N || Banned[NewY][NewX]) continue;

			MannequinBFS.push({ NewX, NewY, Pos.Cost - 1 });
		}
	}

	queue<Position> BFS;
	BFS.push({StartPos.first, StartPos.second, 0});	
	while (!BFS.empty())
	{
		Position Pos = BFS.front();
		BFS.pop();

		Visited[Pos.Y][Pos.X] = true;
		if (Board[Pos.Y][Pos.X] == 2)
		{
			cout << Pos.Cost;
			return 0;
		}

		for (const auto& d : Direction)
		{
			int NewX = Pos.X + d.first;
			int NewY = Pos.Y + d.second;

			if (NewX < 0 || NewY < 0 || NewX >= M || NewY >= N || Visited[NewY][NewX]
				|| Board[NewY][NewX] == 1) continue;

			if (Banned[NewY][NewX]) continue;

			BFS.push({ NewX, NewY, Pos.Cost + 1 });
		}
	}

	cout << "-1";
}

// 1. 