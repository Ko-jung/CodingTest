//정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다.합을 나타낼 때는 수를 1개 이상 사용해야 한다.
//
//1 + 1 + 1 + 1
//1 + 1 + 2
//1 + 2 + 1
//2 + 1 + 1
//2 + 2
//1 + 3
//3 + 1
//정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<int> DP(11, 0);
	for (int TestCase = 0; TestCase < T; TestCase++)
	{
		int N;
		cin >> N;

		DP[1] = 1;
		DP[2] = 2;
		DP[3] = 4;

		for (int i = 4; i <= N; i++)
		{
			DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
		}

		cout << DP[N] << endl;
	}
}