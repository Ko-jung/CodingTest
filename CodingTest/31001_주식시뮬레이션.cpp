// 하이비는 오늘도 주식 시장에 돈을 투자했다가 돈을 잃고 말았다.
// 매일 돈을 잃고만 있는 하이비를 보며 안타까워하던 유틸은 주식 시뮬레이션 프로그램이 담긴 USB를 전달하며 투자 연습을 해보라고 제안했다.
//
//	하이비는 집에 도착해 컴퓨터에 USB를 꽂았다.주식 시뮬레이션 프로그램을 실행해 보니 7가지 메뉴가 나타났다.각 메뉴는 다음과 같다.//
//		1 A B : 회사 A의 주식을 B주 산다.현재 보유하고 있는 현금으로 회사 A의 주식을 B주 살 수 없다면 한 주도 사지 않는다.
//		2 A B : 회사 A의 주식을 B주 판다.현재 보유하고 있는 회사 A의 주식이 S_A주일 때, S_A = 0이라면 아무 일도 일어나지 않는다. B >= S_A라면 S_A주를 모두 판다.
//		3 A C : 회사 A의 주가가 C원 올랐다. C < 0인 경우 주가가 | C | 원 떨어진 것이다.
//		4 D C : D번 그룹에 속하는 회사들의 주가가 C원 올랐다. C < 0인 경우 주가가 | C | 원 떨어진 것이다.
//		5 D E : D번 그룹에 속하는 회사들의 주가가 E % 올랐다. E < 0인 경우 주가가 | E |  % 떨어진 것이다.
//		6 : 현재 하이비가 보유하고 있는 현금을 출력한다.
//		7 : 현재 하이비가 보유하고 있는 주식들을 전부 팔았을 때, 보유하고 있는 현금의 총합을 출력한다.
// 
//	또한 프로그램 매뉴얼에 따르면 다음과 같은 특징이 있다.
//		처음에 하이비가 보유하고 있는 주식은 없다.
//		회사 이름은 대소문자를 구별한다.
//		주식 시뮬레이션 프로그램에서 주식을 사거나 팔 때의 단위는
//		10 원이다. 5번 메뉴의 경우 변동률에 따라 회사들의 주가를 반영하고 난 뒤 일의 자리에서 버림한다.
//		모든 시점에 대해 각 회사의 주가 P_i는 0 <= P_i <= 2 x 10 ^ {9} (1 <= i <= N) 임이 보장된다.
//		모든 시점에 대해 하이비가 보유하고 있는 주식들을 전부 팔았을 때, 보유하고 있는 현금의 총합이 2 x 10 ^ {12} 원을 초과하지 않음이 보장된다.
//		1번, 2번, 3번 메뉴 입력에서 A는 주식 시장에 상장한 회사임이 보장된다.
//		4번 또는 5번 메뉴 입력에서 D번 그룹에 속하는 회사가 하나 이상 존재한다.
//		6번 또는 7번 메뉴 입력은 최소 한 번 이상 주어진다.
// 
// 하이비는 다양한 데이터를 넣어보면서 주식 시뮬레이션을 해보기 시작했다.
// 그런데 한 가지 문제가 있었다. 6번 또는 7번 메뉴를 선택하면 현금이 출력되어야 하는데, 
// 프로그램을 잘못 구현했는지 전부 ? ? ? 로만 뜨는 것이었다.
//
// 하이비는 유틸에게 전화를 걸어 프로그램에 문제가 있다고 이야기했다.
// 그러자 유틸은 입력한 데이터를 전부 주면, 6번 또는 7번 메뉴를 선택했을 때의 결과를 알려주겠다고 했다.
// 하지만 유틸은 지금 다른 프로그램을 만들고 있느라 너무 바빠 여러분에게 이 일을 대신 처리해 줄 수 있겠냐고 부탁했다.
// 유틸을 도와주도록 하자!


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