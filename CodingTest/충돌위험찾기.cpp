//어떤 물류 센터는 로봇을 이용한 자동 운송 시스템을 운영합니다.
// 운송 시스템이 작동하는 규칙은 다음과 같습니다.
//		물류 센터에는(r, c)와 같이 2차원 좌표로 나타낼 수 있는 n개의 포인트가 존재합니다.각 포인트는 1~n까지의 서로 다른 번호를 가집니다.
//		로봇마다 정해진 운송 경로가 존재합니다.운송 경로는 m개의 포인트로 구성되고 로봇은 첫 포인트에서 시작해 할당된 포인트를 순서대로 방문합니다.
//		운송 시스템에 사용되는 로봇은 x대이고, 모든 로봇은 0초에 동시에 출발합니다.로봇은 1초마다 r 좌표와 c 좌표 중 하나가 1만큼 감소하거나 증가한 좌표로 이동할 수 있습니다.
//		다음 포인트로 이동할 때는 항상 최단 경로로 이동하며 최단 경로가 여러 가지일 경우, r 좌표가 변하는 이동을 c 좌표가 변하는 이동보다 먼저 합니다.
//		마지막 포인트에 도착한 로봇은 운송을 마치고 물류 센터를 벗어납니다.로봇이 물류 센터를 벗어나는 경로는 고려하지 않습니다.
// 
//이동 중 같은 좌표에 로봇이 2대 이상 모인다면 충돌할 가능성이 있는 위험 상황으로 판단합니다.
// 관리자인 당신은 현재 설정대로 로봇이 움직일 때 위험한 상황이 총 몇 번 일어나는지 알고 싶습니다.
// 만약 어떤 시간에 여러 좌표에서 위험 상황이 발생한다면 그 횟수를 모두 더합니다.
//
//운송 포인트 n개의 좌표를 담은 2차원 정수 배열 points와 로봇 x대의 운송 경로를 담은 2차원 정수 배열 routes가 매개변수로 주어집니다.
// 이때 모든 로봇이 운송을 마칠 때까지 발생하는 위험한 상황의 횟수를 return 하도록 solution 함수를 완성해 주세요.
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
//// x, y, 지나간 시간
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