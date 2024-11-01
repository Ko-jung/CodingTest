//������ ������ �ѳ��� ������ �������� ����� ���߸� ����ϱ�� �Ͽ���.
// ����� ���� �ʰ� ���߸� ����Ϸ��� ���߸� �������κ��� ��ȣ�ϴ� ���� �߿��ϱ� ������, 
// �ѳ��� ���� ������ ȿ������ �����������̸� �����ϱ�� ����Ѵ�.
// �� �����̴� ���߱�ó�� �����ϸ� ������ ��� �������ν� ���߸� ��ȣ�Ѵ�.
// Ư��, � ���߿� �����������̰� �� ������ ��� ������ �� �����̴� ������ �ٸ� ���߷� �̵��� �� �־�,
// �� ���ߵ� ���� �������κ��� ��ȣ���� �� �ִ�.
// �� ������ �����¿� �� ���⿡ �ٸ� ���߰� ��ġ�� ��쿡 ���� �������ִ� ���̴�.
//
//�ѳ��� ���߸� ����ϴ� ���� ���� ���ؼ� ���߸� �������� �ɾ� ���Ҵ�.
// ���ߵ��� ���ִ� ������ �����������̰� �� ������ ������ �ǹǷ�
// ���� �������ִ� ���ߵ��� �� ������ �����ִ��� �����ϸ� �� �� ������ �����̰� �ʿ����� �� �� �ִ�.
// ���� ��� ���߹��� �Ʒ��� ���� �����Ǿ� ������ �ּ� 5������ �����������̰� �ʿ��ϴ�.
//  0�� ���߰� �ɾ��� ���� ���� ���̰�, 1�� ���߰� �ɾ��� �ִ� ���� ��Ÿ����.
//
// 1	1	0	0	0	0	0	0	0	0
// 0	1	0	0	0	0	0	0	0	0
// 0	0	0	0	1	0	0	0	0	0
// 0	0	0	0	1	0	0	0	0	0
// 0	0	1	1	0	0	0	1	1	1
// 0	0	0	0	1	0	0	1	1	1

#include <iostream>
#include <vector>
#include <array>

using namespace std;

array<array<bool, 50>, 50> Board = { false, };
array<array<bool, 50>, 50> Visited = { false, };

void DFS(int x, int y, int Count)
{
	if (x < 0 || y < 0 || x >= 50 || y >= 50 || !Board[y][x] || Visited[y][x]) return;

	Visited[y][x] = true;

	DFS(x - 1, y, Count);
	DFS(x, y - 1, Count);
	DFS(x + 1, y, Count);
	DFS(x, y + 1, Count);
}

int main()
{
	int T;
	cin >> T;
	for (int TestCase = 0; TestCase < T; TestCase++)
	{
		int M, N, K;
		cin >> M >> N >> K;

		for(auto& board : Board) fill(board.begin(), board.end(), false);
		for(auto& visited : Visited) fill(visited.begin(), visited.end(), false);

		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			Board[Y][X] = true;
		}

		int Count{ 0 };
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Board[i][j] && !Visited[i][j])
				{
					DFS(j, i, ++Count);
				}
			}
		}

		cout << Count << endl;
	}
}