//� ���� ���ʹ� �κ��� �̿��� �ڵ� ��� �ý����� ��մϴ�.
// ��� �ý����� �۵��ϴ� ��Ģ�� ������ �����ϴ�.
//		���� ���Ϳ���(r, c)�� ���� 2���� ��ǥ�� ��Ÿ�� �� �ִ� n���� ����Ʈ�� �����մϴ�.�� ����Ʈ�� 1~n������ ���� �ٸ� ��ȣ�� �����ϴ�.
//		�κ����� ������ ��� ��ΰ� �����մϴ�.��� ��δ� m���� ����Ʈ�� �����ǰ� �κ��� ù ����Ʈ���� ������ �Ҵ�� ����Ʈ�� ������� �湮�մϴ�.
//		��� �ý��ۿ� ���Ǵ� �κ��� x���̰�, ��� �κ��� 0�ʿ� ���ÿ� ����մϴ�.�κ��� 1�ʸ��� r ��ǥ�� c ��ǥ �� �ϳ��� 1��ŭ �����ϰų� ������ ��ǥ�� �̵��� �� �ֽ��ϴ�.
//		���� ����Ʈ�� �̵��� ���� �׻� �ִ� ��η� �̵��ϸ� �ִ� ��ΰ� ���� ������ ���, r ��ǥ�� ���ϴ� �̵��� c ��ǥ�� ���ϴ� �̵����� ���� �մϴ�.
//		������ ����Ʈ�� ������ �κ��� ����� ��ġ�� ���� ���͸� ����ϴ�.�κ��� ���� ���͸� ����� ��δ� ������� �ʽ��ϴ�.
// 
//�̵� �� ���� ��ǥ�� �κ��� 2�� �̻� ���δٸ� �浹�� ���ɼ��� �ִ� ���� ��Ȳ���� �Ǵ��մϴ�.
// �������� ����� ���� ������� �κ��� ������ �� ������ ��Ȳ�� �� �� �� �Ͼ���� �˰� �ͽ��ϴ�.
// ���� � �ð��� ���� ��ǥ���� ���� ��Ȳ�� �߻��Ѵٸ� �� Ƚ���� ��� ���մϴ�.
//
//��� ����Ʈ n���� ��ǥ�� ���� 2���� ���� �迭 points�� �κ� x���� ��� ��θ� ���� 2���� ���� �迭 routes�� �Ű������� �־����ϴ�.
// �̶� ��� �κ��� ����� ��ĥ ������ �߻��ϴ� ������ ��Ȳ�� Ƚ���� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

//struct Position
//{
//	int x;
//	int y;
//	int second;
//};
//
//// x, y, ������ �ð�
//vector<vector<map<int,bool>>> Board(100,vector<map<int, bool>>(100, map<int, bool>()));
//vector<vector<bool>> Visited(100,vector<bool>(100, false));
//vector<pair<int, int>> Direction = { {1,0},{-1,0},{0,1},{0,-1} };
//
//void PrintPath(int x, int y, int TargetX, int TargetY)
//{
//	while (x != TargetX || y != TargetY)
//	{
//		cout << "(" << x << ", " << y << ") -> ";
//
//		for (const auto& d : Direction)
//		{
//			if (0 <= y + d.second && y + d.second < 100 && 0 <= x + d.first && x + d.first < 100)
//			{
//				if (!Board[y + d.second][x + d.first].empty())
//				{
//					x += d.first;
//					y += d.second;
//					break;
//				}
//			}
//		}
//	}
//	cout << "(" << TargetX << ", " << TargetY << ")" << endl;
//}
//
//bool BFS(int x, int y, pair<int,int> Target, int second, int& CrashCount)
//{
//	if (x < 0 || y < 0 || x >= 100 || y >= 100 || Visited[y][x]) return false;
//
//	Visited[y][x] = true;
//
//	int Succ = -1;
//	if (Board[y][x].find(second) == Board[y][x].end())
//	{
//		Board[y][x].insert({ second, false });
//		Succ = 0;
//	}
//	else
//	{
//		if (!Board[y][x][second])
//		{
//			++CrashCount;
//			Board[y][x][second] = true;
//			Succ = 1;
//		}
//	}
//
//	if (x == Target.first && y == Target.second) return true;
//
//	//for (const auto& direction : Direction)
//	//{
//	//	if (BFS(x + direction.first, y + direction.second, Target, second + 1, CrashCount))
//	//		return true;
//	//}
//
//	if (Succ == 1)
//	{
//		--CrashCount;
//		Board[y][x][second] = false;
//	}
//	else if (Succ == 0)
//	{
//		Board[y][x].erase(second);
//	}
//
//	return false;
//}
//
//void StartBFS(pair<int, int> Start, pair<int, int> Target)
//{
//	int CrashCount{ 0 };
//	queue<Position> BFSQ;
//	BFSQ.push({ Start.first, Start.second, 0 });
//	while (!BFSQ.empty())
//	{
//		Position Curr = BFSQ.front();
//		BFSQ.pop();
//		for (const auto& direction : Direction)
//		{
//			int x = Curr.x + direction.first;
//			int y = Curr.y + direction.second;
//			if (x < 0 || y < 0 || x >= 100 || y >= 100 || Visited[y][x]) continue;
//
//			BFSQ.push({ Curr.x + direction.first, Curr.y + direction.second, Curr.second + 1 });
//		}
//
//		if (BFS(Curr.x, Curr.y, { Target.first, Target.second }, Curr.second, CrashCount))
//			break;
//
//		int x = Curr.x;
//		int y = Curr.y;
//
//		Visited[y][x] = true;
//
//		int Succ = -1;
//		if (Board[y][x].find(Curr.second) == Board[y][x].end())
//		{
//			Board[y][x].insert({ Curr.second, false });
//			Succ = 0;
//		}
//		else
//		{
//			if (!Board[y][x][Curr.second])
//			{
//				++CrashCount;
//				Board[y][x][Curr.second] = true;
//				Succ = 1;
//			}
//		}
//
//		if (x == Target.first && y == Target.second) break;
//
//		if (Succ == 1)
//		{
//			--CrashCount;
//			Board[y][x][second] = false;
//		}
//		else if (Succ == 0)
//		{
//			Board[y][x].erase(second);
//		}
//
//		return false;
//	}
//}
//
//int solution(vector<vector<int>> points, vector<vector<int>> routes) {
//	int answer = 0;
//
//	//int CrashCount{ 0 };
//	for (const auto& route : routes)
//	{
//		for (int i = 1; i < route.size(); i++)
//		{
//			int PosX = points[route[i - 1] - 1][0] - 1;
//			int PosY = points[route[i - 1] - 1][1] - 1;
//
//			int TargetX = points[route[i] - 1][0] - 1;
//			int TargetY = points[route[i] - 1][1] - 1;
//
//			Visited.assign(100, vector<bool>(100, false));
//			StartBFS({ PosX, PosY }, { TargetX , TargetY });
//
//			//BFS(PosX, PosY, { TargetX, TargetY }, 0, answer);
//
//			PrintPath(PosX, PosY, TargetX, TargetY);
//		}
//	}
//
//	return answer;
//}

int main()
{
	solution({ {3,2},{6,4},{4,7},{1,4} }, { {4,2},{1,3},{2,4} });
	solution({ {3,2},{6,4},{4,7},{1,4} }, { {4,2},{1,3},{4,2},{4,3} });
	solution({ {2,2},{2,3},{2,7},{6,6},{5,2} }, { {2,3,4,5},{1,3,4,5 } });
}