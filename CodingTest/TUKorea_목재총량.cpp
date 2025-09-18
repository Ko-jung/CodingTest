#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Print(const vector<vector<int>>& Board)
{
	for (auto& board : Board)
	{
		for (auto& b : board)
			cout << b << ", ";
		cout << endl;
	}
}

int Recall(int Index, int Level, vector<int>& Tree)
{
	if (Tree[Index]) return Tree[Index];
	if (!Level) return 0;
	int a = Recall(Index * 2,		Level - 1, Tree);
	int b = Recall(Index * 2 + 1,	Level - 1, Tree);
	Tree[Index] = a + b;
	return Tree[Index];
}

int main()
{
	int M, N;
	cin >> M >> N;
	vector<vector<int>> Board(M, vector<int>(N, 0));
	for (auto& board : Board)
		for (auto& b : board)
			cin >> b;
	Print(Board);

	int C;
	cin >> C;
	vector<tuple<int, int, int, int>> Rect(C, tuple<int, int, int, int>());
	for (int i = 0; i < C; i++)
	{
		auto& [r1, c1, r2, c2] = Rect[i];
		cin >> r1 >> c1 >> r2 >> c2;
		// 1 ~ M까지가 아닌 0 ~ M-1이기 때문
		--r1, --c1, --r2, --c2;
	}

	// 높이h: log(N)
	int H = std::log2(N) + 1;
	// 배열의 수: 2^h;
	int ArrCount = pow(2, H);
	// 리프가 들어가는 배열의 시작점: 2^(h-1)
	int LeafIndex = pow(2, H - 1);

	// 라인 별 부분합
	vector<vector<int>> TreeBoard(M, vector<int>(ArrCount, 0));
	for (int i = 0; i < M; i++)
	{
		// N = 4
		// 1
		// 2 3
		// 45 67 -> 8개 리프 4~7
		// N = 5
		// 1
		// 2 3
		// 45 67
		// 891011 12131415 -> 16개 리프 8~15

		for (int j = LeafIndex; j < ArrCount; j++)
		{
			TreeBoard[i][j] = Board[i][j - LeafIndex];
		}
		Recall(1, H, TreeBoard[i]);
	}

	// 1~3 인덱스 값을 알아야함

}