#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void Print(const vector<vector<int>>& BB)
{
	cout << "+=============================+" << endl;
	for (const auto& bb : BB)
	{
		for (const auto& b : bb)
		{
			cout << b << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<int> Direction = { -1,0,1 };
	int N, M;
	cin >> N >> M;
	vector<vector<int>> Board(N, vector<int>(M, 0));
	vector<vector<pair<int, int>>> DP(N, vector<pair<int, int>>(M, pair<int,int>( numeric_limits<int>::max(), 2 )));
	for (auto& board : Board)
	{
		for (auto& b : board)
		{
			cin >> b;
		}
	}
	for (int i = 0; i < M; i++)
	{
		DP[0][i].first = Board[0][i];
	}
	for (int j = 0; j < N - 1; j++)
	{
		for (int i = 0; i < M; i++)
		{
			for (const auto d : Direction)
			{
				int NewI = i + d;
				if (NewI < 0) continue;
				if (NewI >= M) continue;
				if (DP[j][NewI].second == d) continue;

				if (DP[j + 1][NewI].first >
					DP[j][i].first + Board[j + 1][NewI])
				{
					DP[j + 1][NewI].first = DP[j][i].first + Board[j + 1][NewI];
					DP[j + 1][NewI].second = d;
				}
			}
		}
	}

	int Min = numeric_limits<int>::max();
	for (const auto& s : DP[N - 1])
	{
		Min = min(s.first, Min);
	}
	cout << Min;
}