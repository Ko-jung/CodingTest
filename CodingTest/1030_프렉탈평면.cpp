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

int S, N, K;

bool Recall(const int& x, const int& y, const int& Depth)//, const bool& Answer)
{
	if (Depth == 0) return false;
	int Interval = (N - K) / 2;
	if ((x / N) * N + Interval <= x && x < (x / N) * N + (N - Interval)
		&& (y / N) * N + Interval <= y && y < (y / N) * N + (N - Interval))
	{
		return true;
	}
	return Recall(x / N, y / N, Depth - 1);

	//if (Depth == S)
	//{
	//	Board[y][x] = Answer;
	//	return;
	//}
	//else
	//{
	//	int Len = std::pow(N, Depth);
	//	int Interval = (N - K) / 2;
	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < N; j++)
	//		{
	//			if (Answer || (Interval <= j && j < (N - Interval)
	//				&& Interval <= i && i < (N - Interval)))
	//			{
	//				Recall(Board, x * N + j, y * N + i, S, N, K, Depth + 1, true);
	//			}
	//			else
	//			{
	//				Recall(Board, x * N + j, y * N + i, S, N, K, Depth + 1, false);
	//			}
	//		}
	//	}
	//}
}

int main()
{
	int R1, R2, C1, C2;
	std::cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;

	if (S == 0)
	{
		std::cout << "0";
		return 0;
	}

	for (int j = R1; j <= R2; j++)
	{
		for (int i = C1; i <= C2; i++)
		{
			std::cout << Recall(i, j, S) << " ";
		}
		std::cout << std::endl;
	}
}