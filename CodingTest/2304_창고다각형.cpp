#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int N;
	cin >> N;
	pair<int, int> MaxBlock;
	vector<pair<int, int>> Block(N, { 0,0 });
	for (auto& block : Block)
	{
		cin >> block.first >> block.second;
		if (MaxBlock.second < block.second)
		{
			MaxBlock.first = block.first;
			MaxBlock.second = block.second;
		}
	}
	//sort(Block.begin(), Block.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
	//	return a.first < b.first;
	//	});

	vector<int> Storge((max_element(Block.begin(), Block.end())->first) + 1, 0);
	for (const auto b : Block)
	{
		Storge[b.first] = b.second;
	}
	vector<int> Answer(Storge.size(), 0);

	int LHeight = 0;
	int RHeight = 0;
	for (int i = 0; i <= MaxBlock.first; i++)
	{
		LHeight = max(LHeight, Storge[i]);
		Answer[i] = LHeight;
	}
	for (int i = Storge.size() - 1; i > MaxBlock.first; --i)
	{
		RHeight = max(RHeight, Storge[i]);
		Answer[i] = RHeight;
	}
	cout << accumulate(Answer.begin(), Answer.end(), 0);
}