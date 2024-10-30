//����̴� ���ڿ��� ���� ���ڿ��� �ɾ� ���Ҵ�.
// ���� ���ڿ��� �����ϸ� �� ���ڴ� ���ڿ����� �������, ���� ���ڿ��� �������� �ȴ�.
//
//������ ������ ���� �������� ����ȴ�.//
//		���ڿ��� ���� ���ڿ��� �����ϰ� �ִ� ��쿡, ��� ���� ���ڿ��� �����ϰ� �ȴ�.���� ���ڿ��� ������� �̾� �ٿ� ���ο� ���ڿ��� �����.
//		���� ���� ���ڿ��� ���� ���ڿ��� ���ԵǾ� ���� ���� �ִ�.
//		������ ���� ���ڿ��� ���ڿ��� ���� ������ ��ӵȴ�.
//����̴� ��� ������ ���� �Ŀ� � ���ڿ��� ������ ���غ����� �Ѵ�.�����ִ� ���ڰ� ���� ��찡 �ִ�.�̶��� "FRULA"�� ����Ѵ�.
//
//���� ���ڿ��� ���� ���ڸ� �� �� �̻� �������� �ʴ´�.


#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	string token;

	cin >> str >> token;

	stack<char> Strings;
	for (const auto& s : str)
	{
		Strings.push(s);

		if (s == *token.rbegin())
		{
			if (Strings.empty()) continue;
			if (Strings.size() < token.size()) { continue; }

			string TempStr;
			for (int i = 0; i < token.size(); i++)
			{
				TempStr += Strings.top();
				Strings.pop();
			}

			reverse(TempStr.begin(), TempStr.end());
			if (TempStr != token)
			{
				for (const auto& tstr : TempStr)
					Strings.push(tstr);
			}
		}
	}
	
	string Answer;
	while (!Strings.empty())
	{
		Answer += Strings.top();
		Strings.pop();
	}

	if (Answer.empty())
	{
		cout << "FRULA";
	}
	else
	{
		reverse(Answer.begin(), Answer.end());
		cout << Answer;
	}
}