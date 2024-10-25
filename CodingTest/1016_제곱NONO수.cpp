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

	vector<long long> Check(max - min + 1);
	iota(Check.begin(), Check.end(), min);

	long long Pow{ 0 };
	while (Pow * Pow <= min) ++Pow;
	--Pow;

	for (long long i = 1; i * i <= max; i++)
	{
		if (i == 1) continue;
		if (find(Check.begin(), Check.end(), i * i) == Check.end()) continue;

		auto Index = find(Check.begin(), Check.end(), i * i);
		for (long long j = distance(Check.begin(), Index); j <= (max - min); j += (i * i))
		{
			//cout << Check[j] << " ";
			Check[j] = -1;
		}
		cout << endl;
		//for (auto it = find(Check.begin(), Check.end(), i * i); *it != -1; it += i * i)
		//{
		//	*it = -1;
		//}


		// vector<long long> Remove;
		// Remove.reserve(Check.size() / 2);
		// for (long long j = 0; j < Check.size(); j++)
		// {
		// 	if (Check[j] == -1) continue;
		// 
		// 	if (Check[j] % (i * i) == 0)
		// 	{
		// 		Check[j] = -1;
		// 	}
		// }

		//long long RemoveCount{ 0 };
		//for (const auto& r : Remove)
		//{
		//	Check.erase(Check.begin() + (r - RemoveCount));
		//	RemoveCount++;
		//}
	}
		
	cout << count_if(Check.begin(), Check.end(), [](long long x) {
		return x != -1;
		});
}