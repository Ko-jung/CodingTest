//수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
//
//예를 들어,						수열 A = { 10, 20, 10, 30, 20, 50 } 인 경우에
// 가장 긴 증가하는 부분 수열은		A = { 10, 20, 10, 30, 20, 50 } 이고, 길이는 4이다.


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