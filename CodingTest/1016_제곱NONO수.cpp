//어떤 정수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 그 수를 제곱ㄴㄴ수라고 한다.
// 제곱수는 정수의 제곱이다.min과 max가 주어지면, min보다 크거나 같고, max보다 작거나 같은 제곱ㄴㄴ수가 몇 개 있는지 출력한다.


#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
	long long min, max;
	cin >> min >> max;

	vector<bool> Check(max - min + 1, false);
	for (long long i = 2; i * i <= max; i++)
	{
		// 50, 100 인경우 i가 2라면  n은 12가 나온다 (12 * ( 2 * 2 ) = 48)
		long long n = min / (i * i);

		if (min % (i * i) != 0) ++n;

		while (n * (i * i) <= max)
		{
			if (Check[n * (i * i) - min] == false)
			{
				Check[n * (i * i) - min] = true;
			}
			n++;
		}
	}

	cout << count(Check.begin(), Check.end(), false);
}