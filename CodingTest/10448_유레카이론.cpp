//https://www.acmicpc.net/problem/10448
//�ﰢ�� Tn(n �� 1)��[�׸�]������ ���� ������������ ������ ����� ��Ģ�� ���� ������ �������� ǥ���� �� �ִ�.
//
//
//
//[�׸�]
//
//�ڿ��� n�� ���� n �� 1�� �ﰢ�� Tn�� ����� ������ �ִ�.
//
//Tn = 1 + 2 + 3 + ... + n = n(n + 1) / 2
//
//1796��, ���콺�� ��� �ڿ����� �ִ� 3���� �ﰢ���� ������ ǥ���� �� �ִٰ� �����Ͽ���.���� ���,
//	4 = T1 + T2
//	5 = T1 + T1 + T2
//	6 = T2 + T2 or 6 = T3
//	10 = T1 + T2 + T3 or 10 = T4
// 
//�� ����� ������ ����ϱ� ���� ���� ���̾�� ��Eureka!num = �� + �� + �ġ� ��� �����Ϳ��� ����ī �̷����� �˷�����.
// ���� ��� �ڿ����� ��Ȯ�� 3���� �ﰢ���� ������ ǥ���� �� �ִ��� �ñ�������.
// ���� ���ÿ���, 5�� 10�� ��Ȯ�� 3���� �ﰢ���� ������ ǥ���� �� ������ 4�� 6�� �׷��� �ʴ�.
//
//�ڿ����� �־����� ��, �� ������ ��Ȯ�� 3���� �ﰢ���� ������ ǥ���� �� �ִ��� �������� �Ǵ����ִ� ���α׷��� ������.
// ��, 3���� �ﰢ���� ��� �޶�� �� �ʿ�� ����.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> Arr;

bool combinations_with_replacement(int n, int r, int index, int start, std::vector<int>& current, int Target) {
	if (index == r) {
		// ��� ���
		if (Target == Arr[current[0]] + Arr[current[1]] + Arr[current[2]])
		{
			return true;
		}

		return false;
	}

	for (int i = start; i < n; ++i) {
		current[index] = i;
		if (combinations_with_replacement(n, r, index + 1, i, current, Target)) // ���� �ε���, �ߺ��� ����ϹǷ� i�� �״�� ����
			return true;
	}
	return false;
}

bool BF(int Target)
{
	for (int i = 0; i < Arr.size(); i++)
	{
		for (int j = 0; j < Arr.size(); j++)
		{
			for (int k = 0; k < Arr.size(); k++)
			{
				if (Arr[i] + Arr[j] + Arr[k] == Target) {
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	int T;
	cin >> T;

	Arr.emplace_back(1);
	Arr.emplace_back(3);
	for (int i = 2; i < 1001; i++)
	{
		int a = Arr[i - 1] + i + 1;
		if (Arr[i - 1] + i + 1 > 1000) break;
		Arr.push_back(a);
	}

	// vector<bool> Temp(Arr.size(), false);
	// for (int i = 0; i < 3; i++) { Temp[i] = true; }

	for (int TestCase = 0; TestCase < T; TestCase++)
	{
		int N;
		cin >> N;

		bool IsFind{ false };
		//do {
		//	vector<int> SumArr;
		//	SumArr.reserve(3);
		//	for (int i = 0; i < Arr.size(); i++)
		//	{
		//		if (Temp[i])
		//			SumArr.emplace_back(Arr[i]);
		//	}
		//
		//	if (N == accumulate(SumArr.begin(), SumArr.end(), 0))
		//	{
		//		IsFind = true;
		//		break;
		//	}
		//} while (prev_permutation(Temp.begin(), Temp.end()));

		//vector<int> current(3);
		//while (true)
		//{
		//	if (combinations_with_replacement(Arr.size(), 3, 0, 0, current, N))
		//	{
		//		IsFind = true;
		//		break;
		//	}
		//}

		if (BF(N))
			cout << "1" << endl;
		else
			cout << "0" << endl;

		//if (IsFind) cout << "1" << endl;
		//else cout << "0" << endl;
	}
}