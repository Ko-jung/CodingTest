#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const vector<tuple<int, int, int>> Move = {
	{+1,0,0},
	{-1,0,0},
	{0,+1,0},
	{0,-1,0},
	{0,0,+1},
	{0,0,-1},
};

int main()
{
	int Answer = 0;
	int M, N, K;
	cin >> M >> N >> K;
	vector<vector<vector<char>>> Boards(K, vector<vector<char>>(N, vector<char>(M, 0)));
	for (auto& Board : Boards)
		for (auto& board : Board)
			for (auto& b : board)
			{
				int temp;
				cin >> temp;
				b = temp;
			}

	queue<tuple<char, char, char, int>> BFS;
	set<tuple<char, char, char>> UnTomato;
	for (int h = 0; h < K; h++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < M; i++)
			{
				// Board���� 1(����)�丶�並 ã�Ƽ� BFS�� �ִ´�
				if (Boards[h][j][i] == 1)
				{
					for (const auto& [dX, dY, dZ] : Move)
					{
						int NewX = i + dX;
						int NewY = j + dY;
						int NewZ = h + dZ;

						// ���� üũ
						if (NewX < 0 || NewX >= M ||
							NewY < 0 || NewY >= N ||
							NewZ < 0 || NewZ >= K)
							continue;
							
						// ���� 8ĭ�� ������ �丶�䰡 �ϳ��� ������
						if (Boards[NewZ][NewY][NewX] == 0)
						{
							BFS.emplace(i, j, h, 0);
							break;
						}
					}
				}
				// 0(������) �丶�並 �߰��ϸ� set�� �ִ´�.
				else if (Boards[h][j][i] == 0)
				{
					UnTomato.emplace(i, j, h);
				}
			}
		}
	}

	// BFS���� ������鼭 0�� ������ 1�� �ٲ۴�. �׷��鼭 Set���� ����
	while (!BFS.empty())
	{
		auto [X, Y, Z, Time] = BFS.front();
		BFS.pop();

		cout << (int)X << ", " << (int)Y << ", " << (int)Z << ", " << Time << endl;

		Answer = Time;

		UnTomato.erase({ X, Y, Z });
		if (UnTomato.size() == 0)
			break;


		for (const auto& [dX, dY, dZ] : Move)
		{
			int NewX = X + dX;
			int NewY = Y + dY;
			int NewZ = Z + dZ;

				// ���� üũ
			if (NewX < 0 || NewX >= M ||
				NewY < 0 || NewY >= N ||
				NewZ < 0 || NewZ >= K ||
				// �̹� �;��ų� �丶�䰡 ���°��
				Boards[NewZ][NewY][NewX] == 1 ||
				Boards[NewZ][NewY][NewX] == -1)
				continue;

			BFS.emplace(NewX, NewY, NewZ, Time + 1);

			// �̸� ó��
			Boards[NewZ][NewY][NewX] = 1;
		}
	}

	// BFS�� ������ ��, 0�� ������ -1 ���
	if (UnTomato.size() == 0)
	{
		cout << Answer;
		return 0;
	}

	for (auto& Board : Boards)
		for (auto& board : Board)
			for (auto& b : board)
				if (b == 0)
				{
					cout << "-1";
					return 0;
				}
	cout << Answer;
}