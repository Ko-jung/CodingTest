#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	std::vector<int> Nums(N, 0);
	for (auto& num : Nums)
		cin >> num;

	int Ans = 0;

	int LogLength = N;
	int LogCount = 1;
	bool LastChance = false;
	std::map<int, int> Count;
	int Start = 0, End = 0;
	int OverlapCount = 0;
	int MinOverlapCount = 300'000;

	// 윈도우 슬라이드X 그냥 End 끝까지 밀면서 K + 1이 되는 순간까지 이동
	while (true)
	{
		int M = 0;
		for (; End < LogLength && M == 0; End++)
		{
			if (++Count[Nums[End]] == K + 1)
			{
				M = Nums[End];
			}
			else
				Ans = max(Ans, End - Start);
		}
		if (M)
		{
			for (; Start < End && Start < N && M != 0; Start++)
			{
				if (--Count[Nums[Start]] == K)
					M = 0;
			}
		}
		else
			break;
	}
	cout << Ans;
}