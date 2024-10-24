//n가지 종류의 동전이 있다.
// 각각의 동전이 나타내는 가치는 다르다.
// 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다.
// 그 경우의 수를 구하시오.각각의 동전은 몇 개라도 사용할 수 있다.
//
//사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	// 동전 개수, 합 가치
	int n, k;

	cin >> n >> k;

	vector<int> CoinValue(n + 1, 0);
	for (int i = 1; i < n + 1; i++)
	{
		cin >> CoinValue[i];
	}

	vector<int> DP(k + 1, 0);
	DP[0] = 1;
	for (int j = 1; j < n + 1; j++)
	{
		for (int i = 1; i < k + 1; i++)
		{
			 if (i - CoinValue[j] >= 0)
				DP[i] += DP[i - CoinValue[j]];
		}
	}

	cout << DP[k];
}