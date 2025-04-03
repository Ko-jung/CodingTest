//�����̴� ���迡�� ���� ������ ����� �������� �ñ�������.
// ���� ������ ����� ���ϴ� ����� �� ����� 2 - ģ���� ���ϸ� �ȴ�.
// � ��� A�� �Ǵٸ� ��� B�� 2 - ģ���� �Ǳ� ���ؼ�,
// �� ����� ģ���̰ų�, A�� ģ���̰�, B�� ģ���� C�� �����ؾ� �ȴ�.
// ���⼭ ���� ������ ����� 2 - ģ���� ���� ���� ���� ����̴�.
// ���� ������ ����� 2 - ģ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//A�� B�� ģ����, B�� A�� ģ���̰�, A�� A�� ģ���� �ƴϴ�.

#include <iostream>
#include <vector>
#include <map>
#include <limits>

int main()
{
	int N;
	std::cin >> N;

	// first: X, second: X�� �ƴ»��
	std::multimap<int, int> Friend_2; 
	std::vector<std::vector<char>> Friend(N, std::vector<char>(N, 'N'));
	std::vector<std::vector<bool>> Visited(N, std::vector<bool>(N, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> Friend[i][j];
			if (Friend[i][j] == 'Y')
			{
				Friend_2.insert({j, i});
				Visited[i][j] = true;
				Visited[j][i] = true;
			}
		}
	}

	std::multimap<int, int> Temp = Friend_2;
	for (const auto& m : Temp)
	{
		const auto& Range = Temp.equal_range(m.first);
		for (auto pF = Range.first, pS = (++pF); pS != Range.second; pF++, pS++)
		{
			if (!Visited[pF->second][pS->second])
			{
				Friend_2.insert({ pF->second, pS->second });
				Friend_2.insert({ pS->second, pF->second });
				Visited[pF->second][pS->second] = true;
				Visited[pS->second][pF->second] = true;
			}
		}
	}


	int Max{ std::numeric_limits<int>::min() };
	for (const auto& m : Friend_2)
	{
		const auto& Range = Friend_2.equal_range(m.first);
		int Dist = std::distance(Range.first, Range.second);
		Max = std::max(Max, Dist);
	}

	std::cout << Max;
}