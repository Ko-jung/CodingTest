#include <iostream>
#include <vector>

using namespace std;

bool CheckBoard(const vector<vector<int>>& Board, const int X, const int Y, const int N)
{
	int Standard = Board[Y][X];
	for (int i = Y; i < Y + N; i++)
	{
		for (int j = X; j < X + N; j++)
		{
			if (Board[i][j] != Standard)
			{
				return false;
			}
		}
	}
	return true;
}

int Recursion(const vector<vector<int>>& Board, const int X, const int Y, const int N)
{
	//cout << endl << X << ", " << Y << ", " << N << endl;
	if (CheckBoard(Board, X, Y, N))
	{
		return Board[Y][X];
	}
	const vector<pair<int, int>> Divide = {
		{X,			Y},
		{X + N / 2,	Y},
		{X,			Y + N / 2},
		{X + N / 2,	Y + N / 2},
	};
	cout << "(";
	for (const auto& divide : Divide)
	{
		int Temp = Recursion(Board, divide.first, divide.second, N / 2);
		if (Temp != -1)
			cout << Temp;
	}
	cout << ")";
	return -1;
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> Board(N, vector<int>(N));
	for (auto& board : Board)
		for (auto& b : board)
		{
			char c;
			cin >> c;
			b = (int)(c - '0');
		}

	int Temp = Recursion(Board, 0, 0, N);
	if(Temp != -1)
		cout << Temp;
}