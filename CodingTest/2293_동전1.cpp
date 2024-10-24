//n���� ������ ������ �ִ�.
// ������ ������ ��Ÿ���� ��ġ�� �ٸ���.
// �� ������ ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�.
// �� ����� ���� ���Ͻÿ�.������ ������ �� ���� ����� �� �ִ�.
//
//����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	// ���� ����, �� ��ġ
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