#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> Num = { 2,3 };
	int T;
	cin >> T;
	vector<int> TestCase(T, 0);
	for (auto& t : TestCase)
		cin >> t;

	vector<int> DP (*max_element(TestCase.begin(), TestCase.end()) + 1, 1);
	for (const auto& n : Num)
	{
		for (int i = n; i < DP.size(); i++)
		{
			DP[i] += DP[i - n];
		}
	}

	for (int t : TestCase)
		cout << DP[t] << endl;
}