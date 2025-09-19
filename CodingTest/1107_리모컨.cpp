#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <ranges>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int M;
	cin >> M;
	set<int> ErrorButton;
	for (int i = 0; i < M; i++)
	{
		int m;
		cin >> m;

		ErrorButton.insert(m);
	}

	int Answer = abs(N - 100);

	for (int i = 0; i < 1'000'000; i++)
	{
		string SI = to_string(i);
		bool ErrorButtonFind = false;
		for (const auto& c : SI)
		{
			if (ErrorButton.find(c - '0') != ErrorButton.end())
			{
				ErrorButtonFind = true;
				break;
			}
		}

		if (ErrorButtonFind) continue;

		// �ϴ� �����ߵǴ� ��ư �� (0 ~ 9)
		int Count = SI.length();
		// N�� ���̳��¸�ŭ ���� �� (+, -)
		Count += abs(N - i);
		Answer = min(Answer, Count);
	}

	cout << Answer;
}