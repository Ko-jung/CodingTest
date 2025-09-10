#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int Answer = 0;
	int H, W;
	cin >> H >> W;
	vector<int> Board(W, 0);

	for (auto& board : Board)
	{
		cin >> board;
	}

	for (int level = 0; level <= H; level++)
	{
		int Count = 0;
		bool IsCanCount = false;
		for (int i = 0; i < W; i++)
		{
			// 벽이 있다
			if (level <= Board[i])
			{
				// 벽을 처음 만난다 물을 가둘수있다
				if (!IsCanCount)
				{
					IsCanCount = true;
				}
				// 벽을 만났다 물을 가두고 있었나 보자
				else
				{
					Answer += Count;
					Count = 0;
				}
			}
			else
			{
				if (IsCanCount)
				{
					Count++;
				}
			}
		}
	}

	cout << Answer;
}