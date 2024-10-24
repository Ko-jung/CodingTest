//N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀 있다.
// 내려가기 게임을 하고 있는데, 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이이다.
//
//먼저 처음에 적혀 있는 세 개의 숫자 중에서 하나를 골라서 시작하게 된다.
// 그리고 다음 줄로 내려가는데, 다음 줄로 내려갈 때에는 다음과 같은 제약 조건이 있다.
// 바로 아래의 수로 넘어가거나, 아니면 바로 아래의 수와 붙어 있는 수로만 이동할 수 있다는 것이다.
// 이 제약 조건을 그림으로 나타내어 보면 다음과 같다.
//
// |☆ |   |   |		|   |☆ |   |		|   |   |☆ |
// | O | O | X |		| O | O | O |		| X | O | O |
//
//
//별표는 현재 위치이고, 그 아랫 줄의 파란 동그라미는 원룡이가 다음 줄로 내려갈 수 있는 위치이며, 
// 빨간 가위표는 원룡이가 내려갈 수 없는 위치가 된다.
// 숫자표가 주어져 있을 때, 얻을 수 있는 최대 점수, 최소 점수를 구하는 프로그램을 작성하시오.
// 점수는 원룡이가 위치한 곳의 수의 합이다.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> MaxMem(3, 0);
	vector<int> MinMem(3, 0);
	vector<int> Temp(3, 0);
	vector<int> Input(3);
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> Input[j];
		}

		if (i == 1)
		{
			MaxMem[0] = MinMem[0] = Input[0];
			MaxMem[1] = MinMem[1] = Input[1];
			MaxMem[2] = MinMem[2] = Input[2];
			continue;
		}

		for (int j = 0; j < 3; j++)
		{
			int Max{ (int)0x8000'0000 };
			for (int k = -1; k <= 1; k++)
			{
				if (j + k < 0 || j + k > 2) continue;
				Max = max(Max, MaxMem[j + k] + Input[j]);
			}
			Temp[j] = Max;
		}
		MaxMem = Temp;

		for (int j = 0; j < 3; j++)
		{
			int Min{ (int)0x7FFF'FFFF };
			for (int k = -1; k <= 1; k++)
			{
				if (j + k < 0 || j + k > 2) continue;
				Min = min(Min, MinMem[j + k] + Input[j]);
			}
			Temp[j] = Min;
		}
		MinMem = Temp;
	}

	cout << *max_element(MaxMem.begin(), MaxMem.end()) << " " << *min_element(MinMem.begin(), MinMem.end());

	{	// 메모리 초과
	//vector<vector<int>> MaxMap(n + 1, vector<int>(3, 0));
	//for (int i = 0; i < 3; i++)
	//{
	//	MaxMap[1][i] = Map[0][i];
	//}
	//for (int i = 2; i < n + 1; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		int Max{ (int)0x8000'0000 };
	//		for (int k = -1; k <= 1; k++)
	//		{
	//			if (j + k < 0 || j + k > 2) continue;
	//			Max = max(Max, MaxMap[i - 1][j + k] + Map[i - 1][j]);
	//		}
	//		MaxMap[i][j] = Max;
	//	}
	//}
	//
	//vector<vector<int>> MinMap(n + 1, vector<int>(3, 0));
	//for (int i = 0; i < 3; i++)
	//{
	//	MinMap[1][i] = Map[0][i];
	//}
	//for (int i = 2; i < n + 1; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		int Min{ (int)0x7FFF'FFFF };
	//		for (int k = -1; k <= 1; k++)
	//		{
	//			if (j + k < 0 || j + k > 2) continue;
	//			Min = min(Min, MinMap[i - 1][j + k] + Map[i - 1][j]);
	//		}
	//		MinMap[i][j] = Min;
	//	}
	//}


	//vector<vector<int>> Map(n, vector<int>(3, 0));
	//for (auto& map : Map)
	//{
	//	for (auto& m : map)
	//	{
	//		cin >> m;
	//	}
	//}
	// int MinAnswer, MaxAnswer;
	// vector<vector<int>> AnsMap(n + 1, vector<int>(3, 0));
	// for (int i = 0; i < 3; i++)
	// {
	// 	AnsMap[1][i] = Map[0][i];
	// }
	// for (int i = 2; i < n + 1; i++)
	// {
	// 	for (int j = 0; j < 3; j++)
	// 	{
	// 		int Max{ (int)0x8000'0000 };
	// 		for (int k = -1; k <= 1; k++)
	// 		{
	// 			if (j + k < 0 || j + k > 2) continue;
	// 			Max = max(Max, AnsMap[i - 1][j + k] + Map[i - 1][j]);
	// 		}
	// 		AnsMap[i][j] = Max;
	// 	}
	// }
	// MaxAnswer = *max_element(AnsMap[n].begin(), AnsMap[n].end());
	// 
	// for (int i = 0; i < 3; i++)
	// {
	// 	AnsMap[1][i] = Map[0][i];
	// }
	// for (int i = 2; i < n + 1; i++)
	// {
	// 	for (int j = 0; j < 3; j++)
	// 	{
	// 		int Min{ (int)0x7FFF'FFFF };
	// 		for (int k = -1; k <= 1; k++)
	// 		{
	// 			if (j + k < 0 || j + k > 2) continue;
	// 			Min = min(Min, AnsMap[i - 1][j + k] + Map[i - 1][j]);
	// 		}
	// 		AnsMap[i][j] = Min;
	// 	}
	// }
	// MinAnswer = *min_element(AnsMap[n].begin(), AnsMap[n].end());
	// 
	// cout << MaxAnswer << " " << MinAnswer;
	}
}