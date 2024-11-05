//�÷�� �θ�԰� �Բ� ��ȭ���� ����.
// �θ���� ������ ���� ���� ������ ���� ���� ���ƴٳ�� �ϰ�,
// �÷�� �θ�԰� �Բ� �ɾ�ٴϴ� ���� �ʹ� ���� ���ڿ� �ɾƼ� ������ �Ѵ�.
//
//��ȭ���� ���� ���̰� N, ���� ���̰� M�� ���� �����̰�, �����¿�� ������ ĭ���� �̵��� ������ 1 ��ŭ�� ü���� �Ҹ��Ѵ�.
// �÷�� ���� ��ġ���� ����� ��ȭ�� ������ �ִ� ���� �� �ϳ��� ã�ư��� �������� �Ѵ�.
// �÷�� ��ȭ�� ������ ������ �θ�Բ� ȥ���� ������ ��ȭ�� ������ ���� �� ����.
//
//��ȭ������ �ǹ��� �����ϱ� ���� ��հ� ���� �����ϱ� ���� ����ŷ�� �ִ�.
// �÷�� ����� �ִ� ĭ���� �̵����� ���ϰ�, ����ŷ�� �������ϱ� ������ ����ŷ�� �Ÿ��� K ������ ĭ�� ������� �������� �Ѵ�.
// �̶� �� ĭ (r_x, c_x), (r_y, c_y)�� �Ÿ��� |(r_x - r_y) + (c_x - c_y)| �̴�.
// ��, �÷簡 ����� ���� �θ�԰� �Բ� �ֱ� ������, ��� ������ ����ŷ���� �Ÿ��� K ���ϰ� �Ǿ ����� �� �ִ�.
//
//�÷�� �ٸ��� �ʹ� ������ ������ ü�� �Ҹ� �ּ�ȭ�ϸ鼭 ���ڱ��� ã�ư����� �Ѵ�.�÷簡 �Ҹ��ϴ� ü���� �ּڰ��� ���غ���.

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

	// ����ŷ�� ��ġ�� �������� ������ ��ġ ���ϱ�
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