#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> Rank(N, 0);
	vector<std::pair<int, int>> Body(N, { 0,0 });
	for (auto& body : Body)
	{
		cin >> body.first >> body.second;
	}

	for (int j = 0; j < N; j++)
	{
		int x1 = Body[j].first;
		int y1 = Body[j].second;
		int Count = 1;
		for (int i = 0; i < N; i++)
		{
			int x2 = Body[i].first;
			int y2 = Body[i].second;

			if (x1 < x2 && y1 < y2)
			{
				Count++;
			}
		}
		Rank[j] = Count;
	}

	//int Rank = 1;
	//for (int j = 0; j < N; j++)
	//{
	//	int Max = *max_element(Rank.begin(), Rank.end());
	//
	//}
	for (const auto& i : Rank)
		cout << i << " ";
	cout << endl;
}