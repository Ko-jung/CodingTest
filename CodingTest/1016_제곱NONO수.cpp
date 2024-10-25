//� ���� X�� 1���� ū �������� ������ �������� ���� ��, �� ���� ������������� �Ѵ�.
// �������� ������ �����̴�.min�� max�� �־�����, min���� ũ�ų� ����, max���� �۰ų� ���� ������������ �� �� �ִ��� ����Ѵ�.


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
		// 50, 100 �ΰ�� i�� 2���  n�� 12�� ���´� (12 * ( 2 * 2 ) = 48)
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