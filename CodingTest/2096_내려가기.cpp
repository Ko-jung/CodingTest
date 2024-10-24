//N�ٿ� 0 �̻� 9 ������ ���ڰ� �� ���� ���� �ִ�.
// �������� ������ �ϰ� �ִµ�, �� ������ ù �ٿ��� �����ؼ� ������ �ٿ��� ������ �Ǵ� �����̴�.
//
//���� ó���� ���� �ִ� �� ���� ���� �߿��� �ϳ��� ��� �����ϰ� �ȴ�.
// �׸��� ���� �ٷ� �������µ�, ���� �ٷ� ������ ������ ������ ���� ���� ������ �ִ�.
// �ٷ� �Ʒ��� ���� �Ѿ�ų�, �ƴϸ� �ٷ� �Ʒ��� ���� �پ� �ִ� ���θ� �̵��� �� �ִٴ� ���̴�.
// �� ���� ������ �׸����� ��Ÿ���� ���� ������ ����.
//
// |�� |   |   |		|   |�� |   |		|   |   |�� |
// | O | O | X |		| O | O | O |		| X | O | O |
//
//
//��ǥ�� ���� ��ġ�̰�, �� �Ʒ� ���� �Ķ� ���׶�̴� �����̰� ���� �ٷ� ������ �� �ִ� ��ġ�̸�, 
// ���� ����ǥ�� �����̰� ������ �� ���� ��ġ�� �ȴ�.
// ����ǥ�� �־��� ���� ��, ���� �� �ִ� �ִ� ����, �ּ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ������ �����̰� ��ġ�� ���� ���� ���̴�.


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

	{	// �޸� �ʰ�
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