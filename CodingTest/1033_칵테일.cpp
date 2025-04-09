// august14는 세상에서 가장 맛있는 칵테일이다.
// 이 칵테일을 만드는 정확한 방법은 아직 세상에 공개되지 않았지만, 들어가는 재료 N개는 공개되어 있다.
//
// 경근이는 인터넷 검색을 통해서 재료 쌍 N - 1개의 비율을 알아냈고,
// 이 비율을 이용해서 칵테일에 들어가는 전체 재료의 비율을 알아낼 수 있다.
//
// 총 재료 쌍 N - 1개의 비율이 입력으로 주어진다.
// 이때, 칵테일을 만드는데 필요한 각 재료의 양을 구하는 프로그램을 작성하시오.
// 이때, 필요한 재료의 질량을 모두 더한 값이 최소가 되어야 한다.
// 칵테일을 만드는 재료의 양은 정수이고, 총 질량은 0보다 커야한다.
//
// 비율은 "a b p q"와 같은 형식이고, a번 재료의 질량을 b번 재료의 질량으로 나눈 값이 p / q라는 뜻이다.

#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>
#include <map>

std::multimap<int, int> Node;
std::vector<std::tuple<int, int, int, int>> Ratio;
std::vector<int> Ingredient;
void Recursion(std::vector<bool> Visited, const int NodeNum, const int Multiple)
{
	for (int i = 0; i < Ratio.size(); i++)
	{
		if (Visited[i]) continue;

		int a, b, p, q;
		std::tie(a, b, p, q) = Ratio[i];

		if (a == NodeNum)
		{
			Visited[i] = true;
			Ingredient[b] *= Multiple;
			Recursion(Visited, b, Multiple);
		}
		else if (b == NodeNum)
		{
			Visited[i] = true;
			Ingredient[a] *= Multiple;
			Recursion(Visited, a, Multiple);
		}
	}
}

int main()
{
	int N;
	std::cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, p, q;
		std::cin >> a >> b >> p >> q;
		Ratio.emplace_back(a, b, p, q);

		Node.insert({ a,b });
	}

	// 1. 모든 재료의 질량을 1로 맞춘다
	Ingredient.assign(N, 1);

	for (int i = 0; i < Ratio.size(); i++)
	{
		std::tuple<int, int, int, int> ratio = Ratio[i];

		// 2. a b p q로 입력이 들어오면 a : b = p : q 라는 비율을 가지게 된다
		//	- 1. p q가 최대공약수가 아니라면 최대공약수로 나눠준다.
		//	ex) Input : 2 3 6 8 -> 2 : 3 = 6 : 8 -> 2 : 3 = 3 : 4
		int a, b, p, q;
		std::tie(a, b, p, q) = ratio;

		int GCD = std::gcd(p, q);
		p /= GCD; std::get<2>(ratio) = p;
		q /= GCD; std::get<3>(ratio) = q;

		//	- 2. p, q에 맞는 비율 만큼 a b에 곱한다.
		//	ex) Input : 0 1 9 8 -> x y z : 1 1 1 -> 9 8 1
		Ingredient[a] *= p;
		Ingredient[b] *= q;

		// 3. 추가로 a b와 연관된 다른 노드가 있다면 같이 곱해준다
		//	ex) Input : 0 1 9 8, 1 2 9 8 -> x y z : 1 1 1 -> 1*9 1*8 1*'8' -> 1*9*9 1*8*'9' 1*'8'*8 -> 81 72 64
		for (int j = 0; j < Ratio.size(); j++)
		{
			if (i == j) continue;

			std::tuple<int, int, int, int> r = Ratio[j];
			std::vector<bool> Visited(N, false);
			Visited[i] = true;
			Visited[j] = true;

			int A, B, P, Q;
			std::tie(A, B, P, Q) = r;

			if (a == A)
			{
				Ingredient[B] *= p;
				Recursion(Visited, B, p);
			}
			else if (a == B)
			{
				Ingredient[A] *= p;
				Recursion(Visited, A, p);
			}
			else if (b == A)
			{
				Ingredient[B] *= q;
				Recursion(Visited, B, q);
			}
			else if (b == B)
			{
				Ingredient[A] *= q;
				Recursion(Visited, A, q);
			}
		}
	}

	int GCD = Ingredient[0];
	for (int i = 0; i < Ingredient.size(); i++)
	{
		GCD = std::gcd(GCD, Ingredient[i]);
	}

	for (const auto& ingredient : Ingredient)
	{
		std::cout << ingredient / GCD << " ";
	}
}