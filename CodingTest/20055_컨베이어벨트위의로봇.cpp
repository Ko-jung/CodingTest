#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void Print(const vector<pair<int, bool>>& Conveyors, int N, int RotateCount)
{
	cout << "======Start======" << endl;
	int UpperIndex = ((2 * N - 1) - (RotateCount % (2 * N)));
	int LowerIndex = (N - (RotateCount % (2 * N)) - 1);
	for (int i = 0; i < N; i++)
	{
		int Index = (UpperIndex + i + 1) % (2 * N);

		const auto& Conveyor = Conveyors[Index];
		cout << Conveyor.first << ", ";
	}
	cout << endl;
	for (int i = 2 * N - 1; i >= N; --i)
	{
		int Index = (UpperIndex + i + 1) % (2 * N);
		const auto& Conveyor = Conveyors[Index];
		cout << Conveyor.first << ", ";
	}
	cout << endl << boolalpha;
	for (int i = 0; i < N; i++)
	{
		int Index = (UpperIndex + i + 1) % (2 * N);

		const auto& Conveyor = Conveyors[Index];
		cout << Conveyor.second << ", ";
	}
	cout << endl;
	for (int i = 2 * N - 1; i >= N; --i)
	{
		int Index = (UpperIndex + i + 1) % (2 * N);
		const auto& Conveyor = Conveyors[Index];
		cout << Conveyor.second << ", ";
	}
	cout << endl;
	cout << "======End======" << endl;
}

int main()
{
	// 20:38
	int N, K;
	cin >> N >> K;

	// ������, �κ��� �ִ���
	vector<pair<int, bool>> Conveyors(N * 2, pair<int, bool>(0, false));
	for (auto& i : Conveyors)
		cin >> i.first;

	int LowK = 0;
	int RotateCount = 0;
	//Print(Conveyors, N, RotateCount);

	while (true)
	{
		// 1.	��Ʈ�� �� ĭ ���� �ִ� �κ��� �Բ� �� ĭ ȸ���Ѵ�.
		// 0, 1, 2, 3
		// 3. 0, 1, 2
		// 2, 3, 0, 1
		int UpperIndex = ((2 * N - 1) - (RotateCount % (2 * N)));
		int LowerIndex = (N - (RotateCount % (2 * N)) - 2);
		LowerIndex < 0 ? LowerIndex += 2 * N : LowerIndex;
		if (Conveyors[LowerIndex].second)
			Conveyors[LowerIndex].second = false;
		//cout << UpperIndex << ", " << LowerIndex << endl;
		// 2.	���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�.���� �̵��� �� ���ٸ� ������ �ִ´�.
		//		1.	�κ��� �̵��ϱ� ���ؼ��� �̵��Ϸ��� ĭ�� �κ��� ������, �� ĭ�� �������� 1 �̻� ���� �־�� �Ѵ�.
		for (int i = (N - 1) - 1; i >= 0; --i)
		{
			int Prev = (UpperIndex + i) % (2 * N);
			int Index= (UpperIndex + i + 1) % (2 * N);
			//cout << Prev << "//" << Index << endl;

			// Prev�� �κ��� �����鼭, Index�� �����鼭, Index �������� 0���� Ŭ��
			if (Conveyors[Prev].second && !Conveyors[Index].second && Conveyors[Index].first)
			{
				Conveyors[Prev].second = !Conveyors[Prev].second;
				Conveyors[Index].second = !Conveyors[Index].second;
				if (--Conveyors[Index].first == 0)
					LowK++;
				if(Index == LowerIndex)
					Conveyors[Index].second = false;
			}
		}
		// 3.	�ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ��� �ø���.
		if (Conveyors[UpperIndex].first)
		{
			assert(Conveyors[UpperIndex].second != true);

			Conveyors[UpperIndex].second = true;
			if (--Conveyors[UpperIndex].first == 0)
				LowK++;
		}
		// 4.	�������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�.�׷��� �ʴٸ� 1������ ���ư���.
		if (LowK >= K)
			break;
		RotateCount++;
		//Print(Conveyors, N, RotateCount);
	}

	cout << RotateCount + 1;
}

// 0 1 2
// 5 4 3
// 5 0 1
// 4 3 2
