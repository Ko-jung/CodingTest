//�� ������ ���� ����� �賶�� ���� �����̴�.
//
//�� �� �ĸ� ������ �θ��� �ް� �Ǵ� �ؼ��� ������ ������ �Ѵ�
// ������� ������ �����ϸ� �ִ��� ���� ���� �����̱� ������, ������ �ٴ� �賶 ���� �ִ��� ��ġ �ְ� �η��� �Ѵ�.
//
//�ؼ��� ���࿡ �ʿ��ϴٰ� �����ϴ� N���� ������ �ִ�
// �� ������ ���� W�� ��ġ V�� �����µ�, �ش� ������ �賶�� �־ ���� �ؼ��� V��ŭ ��� �� �ִ�.
// ���� �౺�� �غ� ���� ���� �ؼ��� �ִ� K��ŭ�� ���Ը��� ���� �� �ִ� �賶�� ��� �ٴ� �� �ִ�.
// �ؼ��� �ִ��� ��ſ� ������ �ϱ� ���� �賶�� ���� �� �ִ� ���ǵ��� ��ġ�� �ִ��� �˷�����.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ��ǰ ��, ����
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

			// ���� �� �ִ� ũ�⺸�� �۾Ƽ� ���� �������ڴ�
			if (w > limit)
			{
				DP[row][limit] = DP[row - 1][limit];
			}
			// �� ��ǰ�� ���� �� �ִ�
			else
			{
				// �� ���Ǹ� ����� ��
				//DP[row][limit] = v;

				// �ٸ� ���ǰ� ������ ������ ��
				//DP[row][limit] = DP[row - 1][limit - w] + v;

				// �� �� �� �ִ�

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

	//{	// ��ǰ�� �ߺ��Ǵ� ����, ���Ұ�
	//
	//// ���� �ε����� ��ġ��
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