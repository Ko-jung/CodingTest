//프렉탈 평면은 다음과 같이 커진다.
// 시간 0에서 프렉탈은 흰색 정사각형 하나이다.
// 단위 시간(1)이 진행될 때마다 N×N개의 크기가 동일한 단위 정사각형으로 나누어진다.
// 만약 나누어진 정사각형이 흰색이라면 가운데 K×K 정사각형이 검정색으로 채워진다.
// N과 K는 둘 다 홀수이거나, 둘 다 짝수이다.
//
//예를 들어, N = 3, K = 1이라면, 시간 1에 3×3 정사각형이 된다.
// 가운데 정사각형은 검정색이고, 나머지는 흰색이 된다.시간 2때 9×9 정사각형이 되고, 17개는 검정이고, 나머지는 흰색이다.

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