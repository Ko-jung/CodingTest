//평면 상에 N개의 점이 찍혀있고, 그 점을 집합 P라고 하자.
// 집합 P의 벡터 매칭은 벡터의 집합인데, 모든 벡터는 집합 P의 한 점에서 시작해서, 또 다른 점에서 끝나는 벡터의 집합이다.
// 또, P에 속하는 모든 점은 한 번씩 쓰여야 한다.
//
//벡터 매칭에 있는 벡터의 개수는 P에 있는 점의 절반이다.
//
//평면 상의 점이 주어졌을 때, 집합 P의 벡터 매칭에 있는 벡터의 합의 길이의 최솟값을 출력하는 프로그램을 작성하시오.


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

		// , 현재 매치된 점 개수
		Solve(0, 0);
	}
}