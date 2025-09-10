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
			// ���� �ִ�
			if (level <= Board[i])
			{
				// ���� ó�� ������ ���� ���Ѽ��ִ�
				if (!IsCanCount)
				{
					IsCanCount = true;
				}
				// ���� ������ ���� ���ΰ� �־��� ����
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