// https://www.acmicpc.net/problem/1520
//
// 여행을 떠난 세준이는 지도를 하나 구하였다.
// 이 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다.
// 한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 
// 각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능하다.
//
//현재 제일 왼쪽 위 칸이 나타내는 지점에 있는 세준이는 제일 오른쪽 아래 칸이 나타내는 지점으로 가려고 한다.
// 그런데 가능한 힘을 적게 들이고 싶어 항상 높이가 더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다.
// 위와 같은 지도에서는 다음과 같은 세 가지 경로가 가능하다.
//
//지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 
// 제일 오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.


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