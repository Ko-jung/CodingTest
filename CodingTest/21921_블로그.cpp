#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, X;
	cin >> N >> X;
	vector<int> Visitor(N + 1, 0);
	for (int i = 1; i < Visitor.size(); i++)
	{
		cin >> Visitor[i];
	}
	
	int Ans = 0;
	int Week = 0;
	{
		//슬라이드 윈도우 만들어서 Start는 빼고 End는 넣고
		int Start = 1, End = 1;
		int Sum = 0;
		for (End; End < X; End++)
		{
			Sum += Visitor[End];
		}
		for (Start; Start < Visitor.size() - X + 1; Start++, End++)
		{
			Sum -= Visitor[Start - 1];
			Sum += Visitor[End];
			Ans = max(Ans, Sum);
		}
	}
	{
		//슬라이드 윈도우 만들어서 Start는 빼고 End는 넣고
		int Start = 1, End = 1;
		int Sum = 0;
		for (End; End < X; End++)
		{
			Sum += Visitor[End];
		}
		for (Start; Start < Visitor.size() - X + 1; Start++, End++)
		{
			Sum -= Visitor[Start - 1];
			Sum += Visitor[End];
			//cout << Start << ", " << End << ", " << Sum << endl;
			if (Sum == Ans) Week++;
		}
	}

	if (Ans)
	{
		cout << Ans << endl << Week;
	}
	else
		cout << "SAD";
}