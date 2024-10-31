// � �ڿ��� N�� ���� ��, �� �ڿ��� N�� �������� N�� N�� �̷�� �� �ڸ����� ���� �ǹ��Ѵ�.
// � �ڿ��� M�� �������� N�� ���, M�� N�� �����ڶ� �Ѵ�.
// ���� ���, 245�� �������� 256(= 245 + 2 + 4 + 5)�� �ȴ�.���� 245�� 256�� �����ڰ� �ȴ�.
// ����, � �ڿ����� ��쿡�� �����ڰ� ���� ���� �ִ�.�ݴ��, �����ڰ� ���� ���� �ڿ����� ���� �� �ִ�.
//
//�ڿ��� N�� �־����� ��, N�� ���� ���� �����ڸ� ���س��� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<bool> Candidate(1'000'000, false);
	for (int i = 0; i <= N; i++)
	{
		string IStr = to_string(i);
		vector<int> Nums;
		for (const auto& str : IStr)
		{
			Nums.emplace_back(int(str - '0'));
		}

		if (N == i + accumulate(Nums.begin(), Nums.end(), 0))
		{
			cout << i;
			return 0;
		}
	}

	//cout << count(Candidate.begin(), Candidate.begin() + N, true);
	cout << "0";
}