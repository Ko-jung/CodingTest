#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int Ans = 0;
	// ������ �� N, �ʹ��� ������ d, �����ؼ� �Դ� ������ �� k, ���� ��ȣ c
	int N, D, K, C;
	cin >> N >> D >> K >> C;

	vector<int> Rotate(N, 0);
	for (auto& rotate : Rotate)
		cin >> rotate;

	// �ʹ��� ������ �丮�簡 ������ش�
	bool CouponIncludeInRotate = Rotate.end() != find(Rotate.begin(), Rotate.end(), K);

	int Start = 0;
	int End = 0;
	map<int, int> Select;
	for (int i = 0; i < D; i++)
	{
		Select.emplace(i + 1, 0);
	}
	for ( End = 0; End < K - 1; End++)
	{
		Select[Rotate[End]]++;
	}
	Select[C]++;
	for (Start = 0; Start < N; Start++)
	{
		if (Start != 0)
		{
			Select[Rotate[Start - 1]]--;
		}
		Select[Rotate[End]]++;
		End = (++End) % N;

		//for (const auto s : Select)
		//	cout << s.second << ", ";
		//cout << endl;


		int Count = count_if(Select.begin(), Select.end(), [](const pair<int, int>& a) {
			return a.second != 0;
			});
		Ans = max(Ans, Count);
	}
	cout << Ans;
}