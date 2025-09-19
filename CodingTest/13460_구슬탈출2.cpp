#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
	pair<int, int>	Red;
	pair<int, int>	Blue;
	char Time;
	char Direction;

	NODE() : Red(pair<int, int>()), Blue(pair<int, int>()), Time(0), Direction(0) {};
	NODE(int Rx, int Ry, int Bx, int By, int T, char D) : 
		Red(pair<int, int>(Rx, Ry)), Blue(pair<int, int>(Bx, By)), Time(T), Direction(D)
	{};

};

ostream& operator<<(ostream &os, const NODE& a)
{
	return os << a.Red.first << ", " <<  a.Red.second << ", " << a.Blue.first << ", " << a.Blue.second << ", " << a.Time << ", " << a.Direction;
}

const vector<char> MoveDirection = {
	'U','D','L','R'
};

void WhileMove(vector<vector<char>>& Board, int& X, int& Y, const char Direction, const char Block)
{
	char TempChar = Board[Y][X];
	Board[Y][X] = '.';

	// 한칸 되돌리기용
	int TempX = X, TempY = Y;
	while (Board[Y][X] != '#' && Board[Y][X] == '.')
	{
		TempX = X, TempY = Y;
		switch (Direction)
		{
		case 'U':
			--Y;
			break;
		case 'D':
			++Y;
			break;
		case 'L':
			--X;
			break;
		case 'R':
			++X;
			break;
		default:
			break;
		}
	}

	X = TempX, Y = TempY;
	Board[Y][X] = TempChar;
}

int main()
{
	int N, M;
	cin >> N >> M;

	pair<int, int> Blue;
	pair<int, int> Red;

	vector<vector<char>> Board(N, vector<char>(M));
	for (int i = 0; i < N; i++)
	{
		auto& board = Board[i];
		for (int j = 0; j < M; j++)
		{
			auto& b = board[j];
			cin >> b;
			if (b == 'R')
				Red = { j,i };
			if (b == 'B')
				Blue = { j,i };
		}
	}

	for (int i = 0; i < N; i++)
	{
		auto& board = Board[i];
		for (int j = 0; j < M; j++)
		{
			cout << board[j] << ", ";
		}
		cout << endl;
	}

	queue<NODE> BFS;
	BFS.emplace(Red.first, Red.second, Blue.first, Blue.second, 0, 0);
	while (!BFS.empty())
	{
		NODE NowNode = BFS.front();
		BFS.pop();

		cout << NowNode << endl;

		auto [Rx, Ry] = NowNode.Red;
		auto [Bx, By] = NowNode.Blue;
		int Time = NowNode.Time;
		char Direction = NowNode.Direction;

		if (Time >= 10)
			continue;

		for (const auto& c : MoveDirection)
		{
			if (Direction == c) continue;

			int NewRx = Rx;
			int NewRy = Ry;
			int NewBx = Bx;
			int NewBy = By;

			switch (c)
			{
			case 'U':
				if (NewRy < NewBy)
				{
					WhileMove(Board, NewRx, NewRy, 'U', 'R');
					WhileMove(Board, NewBx, NewBy, 'U', 'B');
				}
				else
				{
					WhileMove(Board, NewBx, NewBy, 'U', 'B');
					WhileMove(Board, NewRx, NewRy, 'U', 'R');
				}
				break;
			case 'D':
				if (NewRy < NewBy)
				{
					WhileMove(Board, NewBx, NewBy, 'D', 'B');
					WhileMove(Board, NewRx, NewRy, 'D', 'R');
				}
				else
				{
					WhileMove(Board, NewRx, NewRy, 'D', 'R');
					WhileMove(Board, NewBx, NewBy, 'D', 'B');
				}
				break;
			case 'L':
				if (NewRx < NewRy)
				{
					WhileMove(Board, NewRx, NewRy, 'L', 'R');
					WhileMove(Board, NewBx, NewBy, 'L', 'B');
				}
				else
				{
					WhileMove(Board, NewBx, NewBy, 'L', 'B');
					WhileMove(Board, NewRx, NewRy, 'L', 'R');
				}
				break;
			case 'R':
				if (NewRx < NewBx)
				{
					WhileMove(Board, NewBx, NewBy, 'R', 'B');
					WhileMove(Board, NewRx, NewRy, 'R', 'R');
				}
				else
				{
					WhileMove(Board, NewRx, NewRy, 'R', 'R');
					WhileMove(Board, NewBx, NewBy, 'R', 'B');
				}
				break;
			default:
				break;
			}

			BFS.emplace(NewRx, NewRy, NewBx, NewBy, Time + 1, c);
		}
	}
}