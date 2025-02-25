/*
문제
	길이 N의 수열 K1, K2, ..., KN과 상수 U, V가 주어진다.
	Q개의 쿼리가 주어지며, 그 종류는 두 가지가 있다.
		1. A, B가 주어지면, max(U × (Ki + Ki + 1 + ... + Kj) + V × (j - i)) (A ≤ i ≤ j ≤ B) 의 값을 구한다.
		2. A, B가 주어지면, KA의 값을 B으로 바꾼다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main()
{
	int N, Q, U, V;
	std::cin >> N >> Q >> U >> V;

	std::vector<int> K;
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		K.push_back(temp);
	}

	int C, A, B;
	std::cin >> C >> A >> B;

	if (C == 0)
	{
		// 1번 쿼리
		int Max{ 0 };
		int i = A, j = B;
		while (true)
		{
			int Sum = U * std::accumulate(K.begin() + i, K.end() - j, 0) + V * (j - i);

			if (Sum > Max)
			{

			}
		}
		do
		{


		} while (true);
	}
	else
	{
		// 2번 쿼리
		K[A] = B;
	}
}