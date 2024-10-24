//이 문제는 아주 평범한 배낭에 관한 문제이다.
//
//한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다
// 세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.
//
//준서가 여행에 필요하다고 생각하는 N개의 물건이 있다
// 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다.
// 아직 행군을 해본 적이 없는 준서는 최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다.
// 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 물품 수, 무게
	int n, k;
	cin >> n >> k;

	int MaxWeight{ 0 };
	vector<pair<int, int>> Stuff;
	for (int i = 0; i < n; i++)
	{
		int w, v;

		cin >> w >> v;

		Stuff.emplace_back(pair<int, int>{w, v});

		if (MaxWeight < w) MaxWeight = w;
	}

	vector<vector<int>> DP(n + 1, vector<int>(k + 1, 0));
	for (int limit = 1; limit < k + 1; ++limit)
	{
		for (int row = 1; row < n + 1; ++row)
		{
			int w = Stuff[row - 1].first;
			int v = Stuff[row - 1].second;

			// 담을 수 있는 크기보다 작아서 전껄 가져오겠다
			if (w > limit)
			{
				DP[row][limit] = DP[row - 1][limit];
			}
			// 이 제품을 담을 수 있다
			else
			{
				// 이 물건만 담았을 때
				//DP[row][limit] = v;

				// 다른 물건과 조합이 가능할 때
				//DP[row][limit] = DP[row - 1][limit - w] + v;

				// 두 개 중 최댓값

				if (limit - w >= 0)
				{
					DP[row][limit] = max(DP[row - 1][limit - w] + v, DP[row - 1][limit]);
				}
				else
				{
					DP[row][limit] = DP[row - 1][limit];
				}
			}
		}
	}

	cout << DP[n][k];

	//{	// 물품이 중복되는 로직, 사용불가
	//
	//// 무게 인덱스에 가치값
	//vector<int> DP;
	//DP.assign(k + 1, 0);
	//	for (const auto& s : Stuff)
	//	{
	//		DP[s.first] = max(DP[s.first], s.second);
	//	}
	//
	//	for (int i = MaxWeight; i < k + 1; i++)
	//	{
	//		for (const auto& s : Stuff)
	//		{
	//			if (i - s.first > 0)
	//			{
	//				DP[i] = max(DP[s.first] + DP[i - s.first], DP[i]);
	//			}
	//		}
	//	}
	//
	//	cout << *max_element(DP.begin(), DP.end());
	//}
}