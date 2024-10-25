//어떤 정수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 그 수를 제곱ㄴㄴ수라고 한다.
// 제곱수는 정수의 제곱이다.min과 max가 주어지면, min보다 크거나 같고, max보다 작거나 같은 제곱ㄴㄴ수가 몇 개 있는지 출력한다.


#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	long long min, max;
	cin >> min >> max;

	vector<int> Check(max - min + 1);
	iota(Check.begin(), Check.end(), min);

	int Pow{ 0 };
	while (Pow * Pow <= min) ++Pow;
	--Pow;

	for (int i = Pow; i * i <= max; i++)
	{
		if (i == 1) continue;

		vector<int> Remove;
		Remove.reserve(Check.size() / 2);
		for (int j = 0; j < Check.size(); j++)
		{
			if (Check[j] % (i * i) == 0) Remove.push_back(j);
		}

		int RemoveCount{ 0 };
		for (const auto& r : Remove)
		{
			Check.erase(Check.begin() + (r - RemoveCount));
			RemoveCount++;
		}
	}

	// 맨 앞 0 제외
	cout << Check.size();
}