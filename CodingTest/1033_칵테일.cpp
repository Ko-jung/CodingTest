// august14�� ���󿡼� ���� ���ִ� Ĭ�����̴�.
// �� Ĭ������ ����� ��Ȯ�� ����� ���� ���� �������� �ʾ�����, ���� ��� N���� �����Ǿ� �ִ�.
//
// ����̴� ���ͳ� �˻��� ���ؼ� ��� �� N - 1���� ������ �˾Ƴ°�,
// �� ������ �̿��ؼ� Ĭ���Ͽ� ���� ��ü ����� ������ �˾Ƴ� �� �ִ�.
//
// �� ��� �� N - 1���� ������ �Է����� �־�����.
// �̶�, Ĭ������ ����µ� �ʿ��� �� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// �̶�, �ʿ��� ����� ������ ��� ���� ���� �ּҰ� �Ǿ�� �Ѵ�.
// Ĭ������ ����� ����� ���� �����̰�, �� ������ 0���� Ŀ���Ѵ�.
//
// ������ "a b p q"�� ���� �����̰�, a�� ����� ������ b�� ����� �������� ���� ���� p / q��� ���̴�.

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

	// 1. ��� ����� ������ 1�� �����
	Ingredient.assign(N, 1);

	for (int i = 0; i < Ratio.size(); i++)
	{
		std::tuple<int, int, int, int> ratio = Ratio[i];

		// 2. a b p q�� �Է��� ������ a : b = p : q ��� ������ ������ �ȴ�
		//	- 1. p q�� �ִ������� �ƴ϶�� �ִ������� �����ش�.
		//	ex) Input : 2 3 6 8 -> 2 : 3 = 6 : 8 -> 2 : 3 = 3 : 4
		int a, b, p, q;
		std::tie(a, b, p, q) = ratio;

		int GCD = std::gcd(p, q);
		p /= GCD; std::get<2>(ratio) = p;
		q /= GCD; std::get<3>(ratio) = q;

		//	- 2. p, q�� �´� ���� ��ŭ a b�� ���Ѵ�.
		//	ex) Input : 0 1 9 8 -> x y z : 1 1 1 -> 9 8 1
		Ingredient[a] *= p;
		Ingredient[b] *= q;

		// 3. �߰��� a b�� ������ �ٸ� ��尡 �ִٸ� ���� �����ش�
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