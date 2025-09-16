#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> Nums(n, 0);

	for (auto& num : Nums)
		cin >> num;

	int x;
	cin >> x;

	// 1 2 3 5 7 9 10 11 12
	sort(Nums.begin(), Nums.end());

	int Ans = 0;
	for (int left = 0; left < Nums.size() - 1; left++)
	{
		int right = left + 1;
		while (Nums[left] + Nums[right] < x && right < Nums.size())
			right++;
		if (Nums[left] + Nums[right] == x)
			Ans++;
	}

	cout << Ans;
}