// https://www.acmicpc.net/problem/1520
//
// ������ ���� �����̴� ������ �ϳ� ���Ͽ���.
// �� ������ �Ʒ� �׸��� ���� ���簢�� ����̸� ���� ĭ���� �������� �ִ�.
// �� ĭ�� �� ������ ��Ÿ���µ� �� ĭ���� �� ������ ���̰� ���� ������, 
// �� ���� ������ �̵��� �������� �����¿� �̿��� �������� �����ϴ�.
//
//���� ���� ���� �� ĭ�� ��Ÿ���� ������ �ִ� �����̴� ���� ������ �Ʒ� ĭ�� ��Ÿ���� �������� ������ �Ѵ�.
// �׷��� ������ ���� ���� ���̰� �;� �׻� ���̰� �� ���� �������θ� �̵��Ͽ� ��ǥ �������� ������ �Ѵ�.
// ���� ���� ���������� ������ ���� �� ���� ��ΰ� �����ϴ�.
//
//������ �־��� �� �̿� ���� ���� ���� �� �������� ����Ͽ� 
// ���� ������ �Ʒ� �������� �׻� ��������θ� �̵��ϴ� ����� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Height, Width;
vector<vector<int>> Map;
vector<vector<int>> DP;
vector<vector<bool>> Visisted;
vector<pair<int, int>> Direction{
	{1 ,0},
	{0 ,1},
	{-1,0},
	{0 ,-1}
};

void DFS(int x, int y)
{
	++DP[y][x];
	for (const auto& d : Direction)
	{
		int NewX = x + d.first;
		int NewY = y + d.second;

		if (NewX < 0 || NewX >= Width || NewY < 0 || NewY >= Height || Map[y][x] <= Map[NewY][NewX]) continue;


		DFS(NewX, NewY);
	}
}

int Recursion(int x, int y)
{
	if (x == Width - 1 && y == Height - 1)		return 1;

	if (DP[y][x] == -1)
	{
		DP[y][x] = 0;
		for (const auto& d : Direction)
		{
			int NewX = x + d.first;
			int NewY = y + d.second;

			if (NewX < 0 || NewX >= Width || NewY < 0 || NewY >= Height || Map[y][x] <= Map[NewY][NewX]) continue;

			DP[y][x] += Recursion(NewX, NewY);
		}
	}

	return DP[y][x];
}

int main()
{
	int x, y;
	cin >> y >> x;

	Height = y, Width = x;

	Map.assign(y, vector<int>(x, 0));
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> Map[i][j];
		}
	}

	Visisted.assign(y, vector<bool>(x, false));
	//DP.assign(y, vector<int>(x, 0));
	//DP[0][0] = 1;
	//DFS(0, 0);

	DP.assign(y, vector<int>(x, -1));
	cout << Recursion(0, 0);
}