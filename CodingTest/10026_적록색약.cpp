//���ϻ����� �������� �ʷϻ��� ���̸� ���� ������ ���Ѵ�.
// ����, ���ϻ����� ����� ���� �׸��� �ƴ� ����� ���� �׸����� �� �ٸ� �� �ִ�.
//
//ũ�Ⱑ N��N�� �׸����� �� ĭ�� R(����), G(�ʷ�), B(�Ķ�) �� �ϳ��� ��ĥ�� �׸��� �ִ�.
// �׸��� �� ���� �������� �������� �ִµ�, ������ ���� ������ �̷���� �ִ�.
// ��, ���� ������ �����¿�� ������ �ִ� ��쿡 �� ���ڴ� ���� ������ ���Ѵ�.
// (������ ���̸� ���� ������ ���ϴ� ��쵵 ���� �����̶� �Ѵ�)
//
//���� ���, �׸��� �Ʒ��� ���� ��쿡
//
//RRRBB
//GGBBB
//BBBRR
//BBRRR
//RRRRR
// 
//���ϻ����� �ƴ� ����� ���� �� ������ ���� �� 4���̴�.(���� 2, �Ķ� 1, �ʷ� 1)
// ������, ���ϻ����� ����� ������ 3�� �� �� �ִ�. (���� - �ʷ� 2, �Ķ� 1)
//
//�׸��� �Է����� �־����� ��, ���ϻ����� ����� ���� ���� �ƴ� ����� ���� �� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<char>> Pic;
vector<vector<int>> Partition;

void FindChar(int x, int y, char c, int num)
{
	if (x < 0 || x >= N || y < 0 || y >= N || Pic[y][x] != c || Partition[y][x] != 0) return;

	Partition[y][x] = num;

	FindChar(x + 1, y, c, num);
	FindChar(x, y + 1, c, num);
	FindChar(x - 1, y, c, num);
	FindChar(x, y - 1, c, num);
}

int main()
{
	cin >> N;

	Pic.assign(N, vector<char>(N));
	for (auto& pic : Pic)
	{
		for (auto& p : pic)
		{
			cin >> p;
		}
	}


	Partition.assign(N, vector<int>(N, 0));
	int Result{ 0 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Partition[i][j] == 0)
			{
				FindChar(j, i, Pic[i][j], ++Result);
			}
		}
	}

	for (auto& p : Pic)
	{
		replace(p.begin(), p.end(), 'R', 'G');
	}
	Partition.assign(N, vector<int>(N, 0));
	int Result2{ 0 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Partition[i][j] == 0)
			{
				char c = Pic[i][j];
				if (Pic[j][i] == 'R')
					Pic[i][j] = 'G';

				FindChar(j, i, c, ++Result2);
			}
		}
	}

	cout << Result << " " << Result2;
}