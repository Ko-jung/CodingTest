#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ranges>

using namespace std;

enum class ERRORCODE {
	Fine, Error,
};

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string Order;
		cin >> Order;

		int N;
		cin >> N;
		deque<int> Nums;

		string Arr;
		cin >> Arr;

		string SNum;
		for (const auto& c : Arr)
		{
			if (c == '[') continue;
			if ((c == ',' || c == ']') && SNum.size() > 0)
			{
				Nums.push_back(stoi(SNum));
				SNum.clear();
			}
			else
			{
				SNum += c;
			}
		}

		vector<deque<int>> Numbers(2);
		bool ReverseNum = false;
		Numbers[0].assign(Nums.begin(), Nums.end());
		reverse(Nums.begin(), Nums.end());
		Numbers[1].assign(Nums.begin(), Nums.end());

		ERRORCODE ErrorCode = ERRORCODE::Fine;
		for (const auto& c : Order)
		{
			if (c == 'R')
			{
				ReverseNum = !ReverseNum;
			}
			else
			{
				if (Numbers[ReverseNum].size() == 0) {
					ErrorCode = ERRORCODE::Error;
					break;
				}

				if (ReverseNum)
				{
					Numbers[0].pop_back();
					Numbers[1].pop_front();
				}
				else
				{
					Numbers[0].pop_front();
					Numbers[1].pop_back();
				}
			}
		}

		if (ErrorCode == ERRORCODE::Error)
		{
			cout << "error" << endl;
		}
		else
		{
			if (Numbers[ReverseNum].size() == 0)
			{
				cout << "[]"  << endl;
				continue;
			}
			cout << "[";
			for (int i = 0; i < Numbers[ReverseNum].size() - 1; i++)
			{
				cout << Numbers[ReverseNum][i] << ",";
			}
			cout << *Numbers[ReverseNum].rbegin() << "]" << endl;
		}

	}
}