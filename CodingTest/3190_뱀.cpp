#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum class TILE {
	EMPTY, WALL, APPLE
};

void Print(const vector<vector<int>>& Board, const vector<pair<int, int>>& SnakePos)
{
	vector<vector<int>> Temp = Board;
	for (const auto& pos : SnakePos)
	{
		Temp[pos.second][pos.first] = '2';
	}
	Temp[SnakePos.rbegin()->second][SnakePos.rbegin()->first] = '1';

	for (auto board : Temp)
	{
		for (auto b : board)
		{
			char c;
			if (b == (int)TILE::EMPTY)
				c = 'O';
			else if (b == (int)TILE::WALL)
				c = 'X';
			else if (b == (int)TILE::APPLE)
				c = 'A';
			else
				c = b;
			cout << c << " ";
		}
		cout << endl;
	}
	cout << "@@@@@@@@@@@@@@@@@@" << endl;

}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<vector<int>> Board(N, vector<int>(N, (int)TILE::EMPTY));
	//Board[0].assign(Board[0].size(), (int)TILE::WALL);
	//Board.rbegin()->assign(Board[0].size(), (int)TILE::WALL);
	for (int i = 0; i < N; i++)
	{
		Board[i]	[0] = (int)TILE::WALL;
		Board[i][N - 1] = (int)TILE::WALL;
		Board[0]	[i] = (int)TILE::WALL;
		Board[N - 1][i] = (int)TILE::WALL;
	}

	vector<pair<int, int>> ApplePos(K,pair<int,int>());
	for (auto& pos : ApplePos)
	{
		cin >> pos.first >> pos.second;
		--pos.first, --pos.second;
		Board[pos.second][pos.first] = (int)TILE::APPLE;
	}

	int L;
	cin >> L;
	vector<char> Command(101, 0);
	for (int i = 0; i < L; i++)
	{
		int f;
		char s;
		cin >> f >> s;
		Command[f] = s;
	}

	static const vector<pair<int, int>> Move = {
		{+1,0},	//R, Direction = 0
		{0,+1},	//D, Direction = 1
		{-1,0},	//L, Direction = 2
		{0,-1},	//U, Direction = 3
	};
	static const map<char, int> Rotate = { {'L', -1}, {'D', +1} };

	// 0번이 꼬리, size() -1 이 머리
	vector<pair<int, int>> SnakePos;
	SnakePos.reserve(10'001);
	SnakePos.emplace_back(1, 1);

	int Direction = 0;
	int Time = 0;
	while (true)
	{
		++Time;

		int HeadIndex = SnakePos.size() - 1, TailIndex = 0;
		auto [NewX, NewY] = SnakePos[HeadIndex];

		// 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
		NewX += Move[Direction].first;
		NewY += Move[Direction].second;

		// 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
		if (Board[NewY][NewX] == (int)TILE::WALL)
		{
			break;
		}

		// 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
		if (Board[NewY][NewX] == (int)TILE::APPLE)
		{
			Board[NewY][NewX] = (int)TILE::EMPTY;
			SnakePos.emplace_back(NewX, NewY);
		}
		// 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
		else
		{
			int TempX = SnakePos[HeadIndex].first, TempY = SnakePos[HeadIndex].second;

			SnakePos[HeadIndex].first = NewX;
			SnakePos[HeadIndex].second = NewY;

			if (SnakePos.size() == 2)
			{
				SnakePos[HeadIndex - 1].first	 = TempX;
				SnakePos[HeadIndex - 1].second	 = TempY;
			}
			else if(SnakePos.size() > 2)
			{
				for (auto it = SnakePos.rbegin() + 2; it != SnakePos.rend(); it++)
				{
					(it - 1)->first = it->first;
					(it - 1)->second = it->second;
				}
			}
		}

		// 게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전
		const auto& it = Rotate.find(Command[Time]);
		if (it != Rotate.end())
		{
			Direction = (Direction + it->second) % 4;
		}
		Print(Board, SnakePos);
	}

	cout << Time;
}