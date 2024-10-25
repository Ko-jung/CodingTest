//� ���� X�� 1���� ū �������� ������ �������� ���� ��, �� ���� ������������� �Ѵ�.
// �������� ������ �����̴�.min�� max�� �־�����, min���� ũ�ų� ����, max���� �۰ų� ���� ������������ �� �� �ִ��� ����Ѵ�.


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

	// �� �� 0 ����
	cout << Check.size();
}