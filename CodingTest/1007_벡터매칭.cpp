//��� �� N���� ���� �����ְ�, �� ���� ���� P��� ����.
// ���� P�� ���� ��Ī�� ������ �����ε�, ��� ���ʹ� ���� P�� �� ������ �����ؼ�, �� �ٸ� ������ ������ ������ �����̴�.
// ��, P�� ���ϴ� ��� ���� �� ���� ������ �Ѵ�.
//
//���� ��Ī�� �ִ� ������ ������ P�� �ִ� ���� �����̴�.
//
//��� ���� ���� �־����� ��, ���� P�� ���� ��Ī�� �ִ� ������ ���� ������ �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<pair<int, int>> Pos;

double VectorSum(double x, double y)
{
	return sqrt(x * x + y * y);
}

void Solve(int n, int k)
{

}

int main()
{
	int T;
	cin >> T;

	for (int TestCase = 0; TestCase < T; TestCase++)
	{
		int N;
		cin >> N;

		Pos.clear();

		for (int i = 0; i < N; i++)
		{
			pair<int, int> Temp;
			cin >> Temp.first >> Temp.second;

			Pos.emplace_back(Temp);
		}

		// , ���� ��ġ�� �� ����
		Solve(0, 0);
	}
}