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

		// 지름길의 도착지가 목적지보다 멀다. 역주행은 안되니
		if (End >= Weight.size()) continue;

		// 새로 갱신될 정보가 원래 정보보다 크니깐 아무것도 안하겠다
		if (Weight[End] <= Weight[Start] + Dist) continue;

		// 새로 갱신될 정보가 더 작다 업데이트 해주자
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