//���ڿ� S�� �־����� ��, S�� ���� �ٸ� �κ� ���ڿ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�κ� ���ڿ��� S���� ���ӵ� �Ϻκ��� ���ϸ�, ���̰� 1���� ũ�ų� ���ƾ� �Ѵ�.
//
//���� ���, ababc�� �κ� ���ڿ��� a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc�� �ְ�, ���� �ٸ����� ������ 12���̴�.

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	cin >> str;

	set<string> Strings;

	for (int i = 1; i <= str.size(); i++)
	{
		for (int j = 0; j + i <= str.size(); j++)
		{
			Strings.insert(str.substr(j, i));
		}
	}

	cout << Strings.size();
}