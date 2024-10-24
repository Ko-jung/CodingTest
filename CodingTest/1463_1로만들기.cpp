// ���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
//
//	1. X�� 3���� ������ ��������, 3���� ������.
//	2. X�� 2�� ������ ��������, 2�� ������.
//	3. 1�� ����.
// ���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�.
// ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> DP;
	DP.assign(n + 1, 0);
	DP[2] = 1;
	DP[3] = 1;

	for (int i = 4; i < n + 1; i++)
	{
		// if (i % 3 == 0)
		// {
		// 	DP[i] = DP[i / 3] + 1;
		// }
		// else
		// {
		// 	int a{ INT_MAX };
		// 	int b{ INT_MAX };
		// 	if (i % 2 == 0)
		// 	{
		// 		a = DP[i / 2] + 1;
		// 	}
		// 	if (i - 1 >= 0)
		// 		b = DP[i - 1] + 1;
		// 
		// 	DP[i] = min(a, b);
		// }

		int a{ INT_MAX };
		int b{ INT_MAX };
		int c{ INT_MAX };
		if (i % 3 == 0)
		{
			c = DP[i / 3] + 1;
		}
		if (i % 2 == 0)
		{
			a = DP[i / 2] + 1;
		}
		if (i - 1 >= 0)
			b = DP[i - 1] + 1;
		
		DP[i] = min(c, min(a, b));
	}

	cout << DP[n] << endl;
}