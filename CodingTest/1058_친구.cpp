//지민이는 세계에서 가장 유명한 사람이 누구인지 궁금해졌다.
// 가장 유명한 사람을 구하는 방법은 각 사람의 2 - 친구를 구하면 된다.
// 어떤 사람 A가 또다른 사람 B의 2 - 친구가 되기 위해선,
// 두 사람이 친구이거나, A와 친구이고, B와 친구인 C가 존재해야 된다.
// 여기서 가장 유명한 사람은 2 - 친구의 수가 가장 많은 사람이다.
// 가장 유명한 사람의 2 - 친구의 수를 출력하는 프로그램을 작성하시오.
//
//A와 B가 친구면, B와 A도 친구이고, A와 A는 친구가 아니다.

#include <iostream>
#include <vector>
#include <map>

int main()
{
	int N;
	std::cin >> N;

	// first: X, second: X를 아는사람
	std::multimap<int, int> Friend_2; 
	std::vector<std::vector<char>> Friend(N, std::vector<char>(N, 'N'));
	std::vector<std::vector<bool>> Visited(N, std::vector<bool>(N, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> Friend[i][j];
			if(i==j) Visited[i][j] = true;
			else if (Friend[i][j] == 'Y')
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
		//const auto& Range = Temp.equal_range(m.first);
		//for (std::multimap<int, int>::iterator pS = Range.first, pF = (pS++); pS != Range.second; pF++, pS++)
		//{
		//	if (!Visited[pF->second][pS->second])
		//	{
		//		Friend_2.insert({ pF->second, pS->second });
		//		Friend_2.insert({ pS->second, pF->second });
		//		Visited[pF->second][pS->second] = true;
		//		Visited[pS->second][pF->second] = true;
		//	}
		//}

		const auto& Range = Temp.equal_range(m.first);
		std::vector<int> NodeIndex;
		for (std::multimap<int, int>::iterator pF = Range.first; pF != Range.second; pF++)
		{
			NodeIndex.emplace_back(pF->second);
		}

		for (int i = 0; i < NodeIndex.size(); i++)
		{
			for (int j = i + 1; j < NodeIndex.size(); j++)
			{
				int f = NodeIndex[i];
				int s = NodeIndex[j];
				if (!Visited[f][s])
				{
					Friend_2.insert({ f, s });
					Friend_2.insert({ s, f });
					Visited[f][s] = true;
					Visited[s][f] = true;
				}
			}
		}
	}


	int Max{ 0 };
	for (const auto& m : Friend_2)
	{
		const auto& Range = Friend_2.equal_range(m.first);
		int Dist = std::distance(Range.first, Range.second);
		Max = std::max(Max, Dist);
	}

	std::cout << Max;
}