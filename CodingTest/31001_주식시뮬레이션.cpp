// ���̺�� ���õ� �ֽ� ���忡 ���� �����ߴٰ� ���� �Ұ� ���Ҵ�.
// ���� ���� �Ұ� �ִ� ���̺� ���� ��Ÿ����ϴ� ��ƿ�� �ֽ� �ùķ��̼� ���α׷��� ��� USB�� �����ϸ� ���� ������ �غ���� �����ߴ�.
//
//	���̺�� ���� ������ ��ǻ�Ϳ� USB�� �ȾҴ�.�ֽ� �ùķ��̼� ���α׷��� ������ ���� 7���� �޴��� ��Ÿ����.�� �޴��� ������ ����.//
//		1 A B : ȸ�� A�� �ֽ��� B�� ���.���� �����ϰ� �ִ� �������� ȸ�� A�� �ֽ��� B�� �� �� ���ٸ� �� �ֵ� ���� �ʴ´�.
//		2 A B : ȸ�� A�� �ֽ��� B�� �Ǵ�.���� �����ϰ� �ִ� ȸ�� A�� �ֽ��� S_A���� ��, S_A = 0�̶�� �ƹ� �ϵ� �Ͼ�� �ʴ´�. B >= S_A��� S_A�ָ� ��� �Ǵ�.
//		3 A C : ȸ�� A�� �ְ��� C�� �ö���. C < 0�� ��� �ְ��� | C | �� ������ ���̴�.
//		4 D C : D�� �׷쿡 ���ϴ� ȸ����� �ְ��� C�� �ö���. C < 0�� ��� �ְ��� | C | �� ������ ���̴�.
//		5 D E : D�� �׷쿡 ���ϴ� ȸ����� �ְ��� E % �ö���. E < 0�� ��� �ְ��� | E |  % ������ ���̴�.
//		6 : ���� ���̺� �����ϰ� �ִ� ������ ����Ѵ�.
//		7 : ���� ���̺� �����ϰ� �ִ� �ֽĵ��� ���� �Ⱦ��� ��, �����ϰ� �ִ� ������ ������ ����Ѵ�.
// 
//	���� ���α׷� �Ŵ��� ������ ������ ���� Ư¡�� �ִ�.
//		ó���� ���̺� �����ϰ� �ִ� �ֽ��� ����.
//		ȸ�� �̸��� ��ҹ��ڸ� �����Ѵ�.
//		�ֽ� �ùķ��̼� ���α׷����� �ֽ��� ��ų� �� ���� ������
//		10 ���̴�. 5�� �޴��� ��� �������� ���� ȸ����� �ְ��� �ݿ��ϰ� �� �� ���� �ڸ����� �����Ѵ�.
//		��� ������ ���� �� ȸ���� �ְ� P_i�� 0 <= P_i <= 2 x 10 ^ {9} (1 <= i <= N) ���� ����ȴ�.
//		��� ������ ���� ���̺� �����ϰ� �ִ� �ֽĵ��� ���� �Ⱦ��� ��, �����ϰ� �ִ� ������ ������ 2 x 10 ^ {12} ���� �ʰ����� ������ ����ȴ�.
//		1��, 2��, 3�� �޴� �Է¿��� A�� �ֽ� ���忡 ������ ȸ������ ����ȴ�.
//		4�� �Ǵ� 5�� �޴� �Է¿��� D�� �׷쿡 ���ϴ� ȸ�簡 �ϳ� �̻� �����Ѵ�.
//		6�� �Ǵ� 7�� �޴� �Է��� �ּ� �� �� �̻� �־�����.
// 
// ���̺�� �پ��� �����͸� �־�鼭 �ֽ� �ùķ��̼��� �غ��� �����ߴ�.
// �׷��� �� ���� ������ �־���. 6�� �Ǵ� 7�� �޴��� �����ϸ� ������ ��µǾ�� �ϴµ�, 
// ���α׷��� �߸� �����ߴ��� ���� ? ? ? �θ� �ߴ� ���̾���.
//
// ���̺�� ��ƿ���� ��ȭ�� �ɾ� ���α׷��� ������ �ִٰ� �̾߱��ߴ�.
// �׷��� ��ƿ�� �Է��� �����͸� ���� �ָ�, 6�� �Ǵ� 7�� �޴��� �������� ���� ����� �˷��ְڴٰ� �ߴ�.
// ������ ��ƿ�� ���� �ٸ� ���α׷��� ����� �ִ��� �ʹ� �ٺ� �����п��� �� ���� ��� ó���� �� �� �ְڳİ� ��Ź�ߴ�.
// ��ƿ�� �����ֵ��� ����!


#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> Inventory;
void AddInventory(string s, int c)
{
	if (Inventory.find(s) == Inventory.end())
	{
		Inventory.insert({ s, c });
	}
	else
	{
		Inventory[s] += c;
	}
}
int FindInventory(string s)
{
	if (Inventory.find(s) == Inventory.end())
	{
		return 0;
	}
	else
	{
		return Inventory[s];
	}
}

int main()
{
	int N,Q;
	long long M;
	cin >> N >> M >> Q;

	multimap<int, string> GroupMap;
	map<string, int> StockMap;
	for (int i = 0; i < N; i++)
	{
		int Group;
		string Name;
		int Stock;
		cin >> Group >> Name >> Stock;

		GroupMap.insert({ Group,Name });
		StockMap.insert({ Name,Stock });
	}

	for (int i = 0; i < Q; i++)
	{
		int Menu;
		cin >> Menu;

		switch (Menu)
		{
		case 1:
		{
			string A;
			int B;
			cin >> A >> B;

			if (M >= StockMap[A] * B)
			{
				AddInventory(A, B);
				M -= (StockMap[A] * B);
			}
			break;
		}
		case 2: 
		{
			string A;
			int B;
			cin >> A >> B;

			int StockCount = FindInventory(A);
			if (StockCount >= B)
			{
				Inventory[A] -= B;
				M += (StockMap[A] * B);
			}
			else
			{
				M += (StockMap[A] * StockCount);
				Inventory.erase(A);
			}
			break;
		}
		case 3: 
		{
			string A;
			int C;
			cin >> A >> C;

			StockMap[A] += C;
			break;
		}
		case 4:
		{
			int D;
			int C;
			cin >> D >> C;

			for (auto it = GroupMap.lower_bound(D); it != GroupMap.upper_bound(D); it++)
			{
				string Name = (*it).second;

				StockMap[Name] += C;
			}
			break;
		}
		case 5: 
		{
			int D;
			int E;
			cin >> D >> E;

			double Percent = (double)E / 100;
			for (auto it = GroupMap.lower_bound(D); it != GroupMap.upper_bound(D); it++)
			{
				string Name = (*it).second;
				double NewValue = (double)StockMap[Name] + ((double)StockMap[Name] * Percent);

				StockMap[Name] = (int)(NewValue / 10) * 10;
			}
			break;
		}
		case 6: 
		{
			cout << M << endl;
			break;
		}
		case 7: 
		{
			long long TempMoney = M;
			for (const auto& inv : Inventory)
			{
				TempMoney += StockMap[inv.first] * inv.second;
			}
			cout << TempMoney << endl;
			break;
		}
		default:
			break;
		}
	}
}