#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
	int N, D;
	cin >> N >> D;
	vector<tuple<int, int, int>> Path(N, tuple<int, int, int>());
	for (auto& path : Path)
	{
		int Start, End, Dist;
		cin >> Start >> End >> Dist;
		path = std::tie(Start, End, Dist);
	}
	sort(Path.begin(), Path.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b){
			return std::get<0>(a) < std::get<0>(b);				
		});

	vector<int> Weight(D + 1);
	iota(Weight.begin(), Weight.end(), 0);

	for (const auto& path : Path)
	{
		int Start, End, Dist;
		std::tie(Start, End, Dist) = path;

		//cout << Start << ", " << End << ", " << Dist << endl;

		// �������� �������� ���������� �ִ�. �������� �ȵǴ�
		if (End >= Weight.size()) continue;

		// ���� ���ŵ� ������ ���� �������� ũ�ϱ� �ƹ��͵� ���ϰڴ�
		if (Weight[End] <= Weight[Start] + Dist) continue;

		// ���� ���ŵ� ������ �� �۴� ������Ʈ ������
		// Start = 0, End = 5, Dist = 2
		// 1 2 3 4 5 6 7 8 9 -> 1 2 3 4 5 '3 4 5 6 7' 
		Weight[End] = Weight[Start] + Dist;
		for (int i = End + 1; i < Weight.size(); i++)
		{
			Weight[i] = min(Weight[i], Weight[i - 1] + 1);
		}
	}

	//for (const auto& w : Weight)
	//	cout << w << ", ";
	//cout << endl;

	cout << *Weight.rbegin();
}