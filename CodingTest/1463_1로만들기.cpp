// 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
//
//	1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
//	2. X가 2로 나누어 떨어지면, 2로 나눈다.
//	3. 1을 뺀다.
// 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
// 연산을 사용하는 횟수의 최솟값을 출력하시오.

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