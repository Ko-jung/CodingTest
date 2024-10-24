//���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//���� ���,						���� A = { 10, 20, 10, 30, 20, 50 } �� ��쿡
// ���� �� �����ϴ� �κ� ������		A = { 10, 20, 10, 30, 20, 50 } �̰�, ���̴� 4�̴�.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> Num(n + 1, 0);
	for (int i = 1; i < n + 1; i++)
	{
		cin >> Num[i];
	}

	vector<int> DP(n + 1, 1);
	DP[1] = 1;
	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (Num[j] < Num[i])
			{
				DP[i] = max(DP[j] + 1, DP[i]);
			}
		}
	}

	cout << *max_element(DP.begin(), DP.end());
}