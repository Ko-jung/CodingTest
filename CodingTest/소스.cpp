#include <string>
#include <vector>
#include <queue>
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Position
{
	int x, y;
	int dist;
};

void print(vector<vector<int>> result)
{
	for (size_t i = 0; i < result.size(); i++) {
		for (size_t j = 0; j < result[i].size(); j++) {
			cout << result[i][j];

			if (j != result[i].size() - 1) {
				cout << " ";
			}
		}

		if (i != result.size() - 1) {
			cout << "\n";
		}
	}

	cout << "\n";
	cout << "\n";
	cout << "\n";
}

bool IsVaild(int x, int y, int n)
{
	return x >= 0 && y >= 0 && x < n && y < n;
}

int bfs(int x, int y, int n)
{
	vector<pair<int, int>> KnightMove = {
		{x,y},{x,-y},{-x,y},{-x,-y},
		{y,x},{y,-x},{-y,x},{-y,-x}
	};

	queue<Position> PositionQueue;
	PositionQueue.push({ 0,0,0 });

	vector<vector<bool>> visited(n, vector<bool>(n, false));

	while (!PositionQueue.empty())
	{
		Position curr = PositionQueue.front();
		PositionQueue.pop();

		if (curr.x == (n - 1) && curr.y == (n - 1)) return curr.dist;

		for (const auto& move : KnightMove)
		{
			int NewX = curr.x + move.first;
			int NewY = curr.y + move.second;

			if (IsVaild(NewX, NewY, n) && !visited[NewX][NewY]) {
				visited[NewX][NewY] = true;
				PositionQueue.push({ NewX,NewY,curr.dist + 1 });
			}
		}
	}
	return -1;
}

vector<vector<int>> knightlOnAChessboard(int n) {

	vector<vector<int>> Result(n - 1, vector<int>(n - 1, 0));

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int value = bfs(i, j, n);

			Result[i - 1][j - 1] = value;
			Result[j - 1][i - 1] = value;

			print(Result);
		}
	}

	return Result;
}

vector<int> Temp()
{
	vector<int> arr{ 203, 204 ,205 ,206 ,207 ,208 ,203 ,204 ,205 ,206 };
	vector<int> brr{ 203, 204 ,204 ,205 ,206 ,207 ,205 ,208 ,203 ,206 ,205 ,206 ,204 };
	vector<int> Result;

	map<int, int> AIndexValueMap;
	for (const auto& a : arr)
	{
		if (AIndexValueMap.find(a) == AIndexValueMap.end())
		{
			AIndexValueMap.insert({ a, 1 });
		}
		else
		{
			AIndexValueMap[a]++;
		}
	}
	map<int, int> BIndexValueMap;
	for (const auto& b : brr)
	{
		if (BIndexValueMap.find(b) == BIndexValueMap.end())
		{
			BIndexValueMap.insert({ b, 1 });
		}
		else
		{
			BIndexValueMap[b]++;
		}
	}

	for (const auto& BMap : BIndexValueMap)
	{
		if (AIndexValueMap.find(BMap.first) != AIndexValueMap.end())
		{
			const pair<int, int> AMap = { BMap.first, AIndexValueMap[BMap.first] };

			if (AMap.second - BMap.second != 0)
			{
				Result.emplace_back(BMap.first);
			}
		}
		else
		{
			Result.emplace_back(BMap.first);
		}
	}

	while (!arr.empty())
	{
		if (arr[0] == brr[0])
		{
			arr.erase(arr.begin());
			brr.erase(brr.begin());
		}
		else
		{
			Result.emplace_back(brr[0]);
			brr.erase(brr.begin());
		}

		//auto it = std::find(brr.begin() + i, brr.end(), arr[i]);
		//if (it != brr.end())
		//{
		//	arr.erase(arr.begin() + i);
		//	brr.erase(it);
		//	--i;
		//}
		//else
		//{
		//	Result.emplace_back(*it);
		//}
	}
	return Result;
}

int pairs(int k, vector<int> arr) {
	sort(arr.begin(), arr.end());
	int Result = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[j] - arr[i] == k) Result++;
			if (arr[j] - arr[i] > k) break;
		}
	}
	return Result;
}

bool FrogIsValid(int i, int j, int n, int m)
{
	return i >= 0 && j >= 0 && i < n && j < m;
}

pair<int, int> FrogGetCharPos(char c, const vector<string>& map)
{
	for (int i = 0; i < map.size(); i++)
	{
		auto n = map[i].find(c);
		if (n != string::npos)
		{
			return pair<int, int>{i, n};
		}
	}

	return pair<int, int>{-1,-1};
}

void ForgInMaze()
{
	//시도, 성공
	int Try = 0, Succ = 0;

	// 세로, 가로, 터널개수
	int n = 3, m = 7, k = 0;

	// #: 벽, *: 폭탄, O: 이동가능
	// A: 초기 위치, %: 출구
	// (터널 위치, 터널 위치)
	vector<string> Map = {
		"##OOO##",
		"%OOAOO*",
		"##OOO##"
	};

	vector<vector<bool>> Visited(n, vector<bool>(m, false));

	vector<pair<int, int>> TunnelList;
	TunnelList.emplace_back(pair<int, int>{2, 3});
	TunnelList.emplace_back(pair<int, int>{2, 1});

	stack<Position> DFS;
	auto CharPos = FrogGetCharPos('A', Map);
	DFS.push({CharPos.first, CharPos.second, 0});
	Visited[CharPos.first][CharPos.second] = true;

	vector<pair<int, int>> Direction = {
		{1,0},{-1,0},{0,1},{0,-1}
	};

	while (!DFS.empty())
	{
		const Position pos = DFS.top();
		DFS.pop();

		bool IsCanMove = false;
		for (int i = 0; i < 4; i++)
		{
			int NewX = pos.x + Direction[i].first;
			int NewY = pos.y + Direction[i].second;
			if (FrogIsValid(NewX, NewY, n, m) && Map[NewX][NewY] != '#')
			{
				// Checking Tunnel
				if (k > 0)
				{
					for (int j = 0; j < TunnelList.size(); j++)
					{
						const auto& T = TunnelList[j];
						if (NewX == T.first - 1 && NewY == T.second - 1)
						{
							Visited[NewX][NewY] = true;
							if (j % 2 == 0)
							{
								NewX = TunnelList[j + 1].first - 1;
								NewY = TunnelList[j + 1].second - 1;
								break;
							}
							else
							{
								NewX = TunnelList[j - 1].first - 1;
								NewY = TunnelList[j - 1].second - 1;
								break;
							}
						}
					}
				}

				if (Visited[NewX][NewY] == false)
				{
					// Check Tile
					if (Map[NewX][NewY] == '%')
					{
						++Try;
						++Succ;
						cout << "%" << endl;
						continue;
					}
					if (Map[NewX][NewY] == '*')
					{
						++Try;
						cout << "*" << endl;
						continue;
					}

					DFS.push({ NewX, NewY, pos.dist + 1});
					Visited[NewX][NewY] = true;
				}

				IsCanMove = true;
			}
		}

		if (!IsCanMove)
		{
			++Try;
			cout << "IsCanMove" << endl;
			continue;
		}
		
	}



	double Result = (double)Succ / Try;
	cout << Result << endl;
}

int main()
{
	//string n_temp;
	//getline(cin, n_temp);

	//Temp();
	//pairs(2, {1,5,3,4,2});
	ForgInMaze();

	return 0;
}