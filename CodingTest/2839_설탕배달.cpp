//����̴� ���� �������忡�� ������ ����ϰ� �ִ�.
// ����̴� ���� �������Կ� ������ ��Ȯ�ϰ� Nų�α׷��� ����ؾ� �Ѵ�.
// �������忡�� ����� ������ ������ ����� �ִ�.������ 3ų�α׷� ������ 5ų�α׷� ������ �ִ�.
//
//����̴� ������ ������, �ִ��� ���� ������ ��� ������ �Ѵ�.
// ���� ���, 18ų�α׷� ������ ����ؾ� �� ��, 
// 3ų�α׷� ���� 6���� �������� ������, 5ų�α׷� 3���� 3ų�α׷� 1���� ����ϸ�, �� ���� ������ ������ ����� �� �ִ�.
//
//����̰� ������ ��Ȯ�ϰ� Nų�α׷� ����ؾ� �� ��, ���� �� ���� �������� �Ǵ��� �� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>

using namespace std;
vector<int> Counts;

int Suger(int n, int count)
{
	if (n < 0) return -1;
	else if (n == 0) return count + 1;

	if (Counts[n] == 0)
	{
		auto c5 = Suger(n - 5, count);
		if (c5 != -1) 
		{ 
			Counts[n] = c5;
			return c5 + 1;
		}

		auto c3 = Suger(n - 3, count);
		if (c3 != -1)
		{
			Counts[n] = c3;
			return c3 + 1;
		}

		Counts[n] = -1;
		return -1;
	}
	else
	{
		return Counts[n];
	}
}

int main()
{
	int n;
	cin >> n;

	Counts.assign(n + 1, 0);

	int count = 0;

	count = Suger(n, 0);

	cout << ((count == -1) ? -1 : (count - 1)) << endl;
}