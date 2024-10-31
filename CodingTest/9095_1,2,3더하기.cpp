//���� 4�� 1, 2, 3�� ������ ��Ÿ���� ����� �� 7������ �ִ�.���� ��Ÿ�� ���� ���� 1�� �̻� ����ؾ� �Ѵ�.
//
//1 + 1 + 1 + 1
//1 + 1 + 2
//1 + 2 + 1
//2 + 1 + 1
//2 + 2
//1 + 3
//3 + 1
//���� n�� �־����� ��, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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