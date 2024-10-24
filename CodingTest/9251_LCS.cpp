//LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때,
// 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
//
//예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string A;
	string B;

	cin >> A >> B;

	int Longest{ 0 };
	vector<vector<int>> DP(B.size() + 1, vector<int>(A.size() + 1, 0));
	for (int j = 1; j < B.size() + 1; ++j)
	{
		string NewB = B.substr(0, j + 1);
		//cout << NewB << endl;

		for (int i = 1; i < A.size() + 1; i++)
		{
			if (A[i - 1] == B[j - 1])
			{
				DP[j][i] = DP[j - 1][i - 1] + 1;
			}
			else
			{
				DP[j][i] = max(DP[j - 1][i], DP[j][i - 1]);
			}
		}
	}

	cout << DP[B.size()][A.size()];
}