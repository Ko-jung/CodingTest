//����Ż ����� ������ ���� Ŀ����.
// �ð� 0���� ����Ż�� ��� ���簢�� �ϳ��̴�.
// ���� �ð�(1)�� ����� ������ N��N���� ũ�Ⱑ ������ ���� ���簢������ ����������.
// ���� �������� ���簢���� ����̶�� ��� K��K ���簢���� ���������� ä������.
// N�� K�� �� �� Ȧ���̰ų�, �� �� ¦���̴�.
//
//���� ���, N = 3, K = 1�̶��, �ð� 1�� 3��3 ���簢���� �ȴ�.
// ��� ���簢���� �������̰�, �������� ����� �ȴ�.�ð� 2�� 9��9 ���簢���� �ǰ�, 17���� �����̰�, �������� ����̴�.

#include <iostream>
#include <vector>
#include <cmath>

void Recall(std::vector<std::vector<bool>>& Board, const int& x, const int& y, const int& S, const int& N, const int& K,  const int& Depth, const bool& Answer)
{
	if (Depth == S)
	{
		Board[y][x] = Answer;
		return;
	}
	else
	{
		int Len = std::pow(N, Depth);
		int Interval = (N - K) / 2;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (Answer || (Interval <= j && j < (N - Interval)
					&& Interval <= i && i < (N - Interval)))
				{
					Recall(Board, x * N + j, y * N + i, S, N, K, Depth + 1, true);
				}
				else
				{
					Recall(Board, x * N + j, y * N + i, S, N, K, Depth + 1, false);
				}
			}
		}
	}
}

int main()
{
	int S, N, K, R1, R2, C1, C2;
	std::cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;

	int Line = std::pow(N, S);
	std::vector<std::vector<bool>> Board(Line, std::vector<bool>(Line, false));

	Recall(Board, 0, 0, S, N, K, 0, false);
	//for (int i = 1; i <= S; i++)
	//{
	//	int Len = std::pow(N, i);
	//	std::vector<std::vector<bool>> b(Len, std::vector<bool>(Len, false));
	//	for (int y = 0; y < Len; y++)
	//	{
	//		for (int x = 0; x < Len; x++)
	//		{
	//			int Interval = (N - K) / 2;
	//			if(Interval <= x < Len)
	//		}
	//	}
	//}

	for (int j = R1; j <= R2; j++)
	{
		for (int i = C1; i <= C2; i++)
		{
			std::cout << Board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}