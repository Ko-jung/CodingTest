#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	vector<int> Card(n, 0);
	for (auto& c : Card)
		cin >> c;
	sort(Card.begin(), Card.end());

	vector<bool> Marking(n, false);
	Marking[0] = true;	Marking[1] = true;	Marking[2] = true;
	//cout << boolalpha;

	int Max = 0;
	do
	{
		int Sum = 0;
		for (int i = 0; i < n; i++)
		{
			//cout << Marking[i] << ' ';
			if (Marking[i])
				Sum += Card[i];
		}
		//cout << endl;

		if (Sum <= m)
			Max = std::max(Max, Sum);
	} while (prev_permutation(Marking.begin(), Marking.end()));

	cout << Max;
}